(function() {

'use strict';

angular.module("ShoppingListCheckOff", [])
.controller("ToBuyController", ToBuyController)
.controller("AlreadyBoughtController", AlreadyBoughtController)
.service("ShoppingListCheckOffService", ShoppingListCheckOffService);


ToBuyController.$inject = ["ShoppingListCheckOffService"];
function ToBuyController(ShoppingListCheckOffService) {
	var toBuyList = this;

	toBuyList.items = ShoppingListCheckOffService.getItemsToBuy();

	toBuyList.addToBought = function(itemName, amount, index) {
		ShoppingListCheckOffService.addToBought(itemName, amount, index);
	}

}


AlreadyBoughtController.$inject = ["ShoppingListCheckOffService"];
function AlreadyBoughtController(ShoppingListCheckOffService) {
	var boughtList = this;

	boughtList.items = ShoppingListCheckOffService.getItemsBought();
}


function ShoppingListCheckOffService() {
	var service = this;
	var itemsBought = [];
	var toBuyList = [{name: "cookies", quantity: 10}, {name: "chocolate", quantity: 30}, {name: "kale", quantity: 0}, {name: "cake", quantity: 5}, {name: "reeses", quantity: 15}];

	service.addToBought = function(itemName, amount, index) {
		var item = {
			name: itemName,
			quantity: amount
		};

		toBuyList.splice(index, 1);
		itemsBought.push(item);
	}

	service.getItemsBought = function() {
		return itemsBought;
	};


	service.getItemsToBuy = function() {
		return toBuyList;
	};


}


})();










