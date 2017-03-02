(function() {

'use strict';


angular.module('LunchCheck', [])

.controller('LunchController', LunchController);

// Parse DI for minification.
LunchController.$inject = ['$scope'];


function LunchController($scope) {
	$scope.lunch = "";

	// Envoke on click.
	$scope.displayLunch = function() {
		// set to totalLunch to calculate lunch value.
		var totalLunchValue = calculateLunch($scope.lunch);

		// put value on scope object.
		$scope.totalLunch = totalLunchValue;
	}


	function calculateLunch(lunch) {
		var lunchArr = lunch.split(',');
	 if(lunchArr.length <= 3 && lunchArr.length !== 1) {
			return "Enjoy!";
		} else if(lunchArr.length > 3) {
			return "Too much!" ;
		} else {
			return "Please enter data first";
		}
	}
};

})();










