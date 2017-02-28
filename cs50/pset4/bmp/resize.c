/****************************************************************************
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Resize a bmp photo by 1 - n
 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // Ensure proper usage
    if (argc != 4)
    {
        printf("Usage: resize factor infile outfile\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    
    int factor = atoi(argv[1]);
    
    // check if factor is 1 -100
    if (factor < 1 || factor > 100)
    {
        printf("Factor must be in range 1..100!\n");
        return 1;
    }

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bf_resize;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bf_resize = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, bi_resize;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    bi_resize = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // resize via factor argv bitmap infoheader
    bi_resize.biWidth  = bi.biWidth * factor;
    bi_resize.biHeight = bi.biHeight * factor;
    
    // padding
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) %4) % 4;
    int resize_padding = (4 - (bi_resize.biWidth * sizeof(RGBTRIPLE)) %4) % 4;
    
    // image size (the whole thing)
    bi_resize.biSizeImage = (bi_resize.biWidth * sizeof(RGBTRIPLE) + resize_padding) * abs(bi_resize.biHeight);
    bf_resize.bfSize = bf.bfSize - bi.biSizeImage + bi_resize.biSizeImage;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_resize, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_resize, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // Read each scanline factor times
        for (int j = 0; j < factor; j++)
        {  
            // iterate over pixels in scanline
            for (int k = 0; k < bi.biWidth; k++)
            {
                // tmp
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // use the factor to print each pixel.
                for (int l = 0; l < factor; l++)
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);    
            }
            
            // Add a new padding
            for (int l = 0; l < resize_padding; l++)
                fputc(0x00, outptr);
            
            // Return to the beginning of a scanline
            if (j < factor - 1)
                fseek(inptr, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
        }

        // Skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
