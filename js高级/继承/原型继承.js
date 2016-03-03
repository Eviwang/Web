function PersonBase() {
    this.color = [1, 2, 3];
}

function Person(name) {
    this.name = name;
};

Person.prototype = new PersonBase();


var p1 = new Person("A");
p1.color.push(4);

var p2 = new Person("B");

