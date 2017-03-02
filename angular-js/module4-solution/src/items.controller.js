(function() {

'use strict';


angular.module('MenuApp')
.controller('ItemsController', ItemsController);

ItemsController.$inject = ['items'];
function ItemsController(items) {
        var $ctrl = this;
        

        console.log('items controller', $ctrl.category)
        $ctrl.items = items.data;
        $ctrl.hello = "Hello World!";
}
})();