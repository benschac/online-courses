(function() {

'use strict';

angular.module('MenuApp')
.config(RoutesConfig);


RoutesConfig.$inject = ['$stateProvider', '$urlRouterProvider'];
function RoutesConfig($stateProvider, $urlRouterProvider) {

	$urlRouterProvider.otherwise('/');

	$stateProvider

	.state('home', {
		url: '/',
		templateUrl: 'src/templates/home.template.html'
	})

	.state('categories', {
		url: '/categories',
		templateUrl: 'src/templates/main-categories.template.html',
		controller: 'CategoriesController as catCtrl',
		resolve: {
			categories: ['MenuDataService', function(MenuDataService) {
				return MenuDataService.getAllCategories();
			}]
		}
	})

	.state('items', {
		url: '/items/{short_name}',
		templateUrl: 'src/templates/main-items.template.html',
		controller: 'ItemsController as itemsCtrl',
		resolve: {
			items: [ 'MenuDataService', function($stateParams, MenuDataService) {
				return MenuDataService.getItemsForCategory($stateParams.short_name);
			}
			]
		}
	});

}



})();