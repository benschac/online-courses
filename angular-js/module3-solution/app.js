(function() {

'use strict';

angular.module('NarrowItDownApp', [])
.controller('NarrowItDownController', NarrowItDownController)
.service('MenuSearchService', MenuSearchService)
.directive('foundItems', FoundItemsDirective)
.constant('ApiBasePath', "http://davids-restaurant.herokuapp.com");



function FoundItemsDirective() {
	var ddo = {
		restrict: 'E',
		templateUrl: 'found-items.html',
		controller: NarrowItDownController,
		controllerAs: 'narrow',
		bindToController: true
	};
	console.log(ddo);
	return ddo;
}


NarrowItDownController.$inject = ['MenuSearchService'];
function NarrowItDownController(MenuSearchService) {
	var nd = this;
	// Inputfield -- ng-model 2-way data binding.
	nd.description = "";

	nd.search = function(searchTerm) {
		console.log(this);
		var promise = MenuSearchService.getMatchedMenuItems(searchTerm);

		promise.then(function(response) {
			nd.found = response;
		})
		.catch(function (error) {
    		console.log("Something went terribly wrong.");
  		});
	}

	nd.removeItem = function(item) {
		nd.found.splice(item, 1);
	}

};


MenuSearchService.$inject = ['$http', 'ApiBasePath'];
function MenuSearchService($http, ApiBasePath) {
	var menuSearch = this;

	menuSearch.getMatchedMenuItems = function(searchTerm) {
		var response = $http({
			method: "GET",
			url: (ApiBasePath + '/menu_items.json')
		})
		.then(function(result) {

			if(!searchTerm.length) {
				return;
			} 

			else {
				return result.data.menu_items.filter(function(el) {
					return el.description.indexOf(searchTerm) !== -1;
				});
			}
		});

		return response;

	};
}



})();