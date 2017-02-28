function run(genFunc) {
	const genObject = genFunc();

	function iterate(iteration) {
		if(iteration.done) {
			return Promise.resolve(iteration.value);
		}

		return Promise.resolve(iteration.value)
		.then(x => iterate(genObject.next(x)))
		.catch(x => iterate(genObject.throw(x)));
	}
}