(function() {


'use strict';



angular.module('public')
.controller('InfoController', InfoController);



InfoController.$inject = ['user'];
function InfoController(user) {
	var info = this;
	info.user = user;
	console.log('info user', info.user);
	};
})();