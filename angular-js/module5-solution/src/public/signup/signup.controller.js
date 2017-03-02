(function(){

'use strict';



angular.module('public')
.controller('SignupController', SignupController);

SignupController.$inject = ['MenuService'];

function SignupController(MenuService) {
	var signup = this;


	signup.submit = function() {
		MenuService.getMenuItem(signup.user.short_name).then(function(response) {
			signup.user.short_name = response;
			MenuService.setUser(signup.user);
			signup.success = true;
			signup.error = false;
			
		}, function(response) {
			signup.success = false;
			signup.error = true;
		});
	}


}


})();