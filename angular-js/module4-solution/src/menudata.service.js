(function() {

'use strict';


angular.module('data')
.service('MenuDataService', MenuDataService)
.constant('baseApi', 'https://davids-restaurant.herokuapp.com');


MenuDataService.$inject = ['$http', 'baseApi'];
function MenuDataService($http, baseApi) {
	var menuData = this;

	// First pass.
	menuData.getAllCategories = function() {
		var response = $http({
			method: 'GET',
			url: (baseApi + '/categories.json')
		}).then(function(response) {
			console.log('all categories', response.data);
			return response.data;
		});


		return response;
	};


	// First pass
	menuData.getItemsForCategory = function(categoryShortName) {
		var response = $http({
			method: 'GET',
			url: (baseApi + '/menu_items.json'),
			params: {
				category: categoryShortName
			}
			
		}).then(function(response) {
			console.log('get items', response.data);
			return response.data;
		});

		return response;
	};
}

})();