"use strict";

var _marked = [test].map(regeneratorRuntime.mark);

var ui1 = document.getElementById("ui1");
var ui2 = document.getElementById("ui2");
var ui3 = document.getElementById("ui3");
var ui4 = document.getElementById("ui4");

showTextIn(ui1, "[A]: This line will display in 1 second.", 1000).then(function () {
    showTextIn(ui3, "[C]: This line will appears after [A] appears.", 1000);
});
showTextIn(ui2, "[B]: this line will latest for 2 seconds.", 2000);

showTextWithUnderscore(ui4, "[D]: this line underscore flashes.", 3000);

function test() {
    var i;
    return regeneratorRuntime.wrap(function test$(_context) {
        while (1) {
            switch (_context.prev = _context.next) {
                case 0:
                    i = 0;

                case 1:
                    if (!(i < 10)) {
                        _context.next = 7;
                        break;
                    }

                    _context.next = 4;
                    return i;

                case 4:
                    ++i;
                    _context.next = 1;
                    break;

                case 7:
                case "end":
                    return _context.stop();
            }
        }
    }, _marked[0], this);
}
var _iteratorNormalCompletion = true;
var _didIteratorError = false;
var _iteratorError = undefined;

try {
    for (var _iterator = test()[Symbol.iterator](), _step; !(_iteratorNormalCompletion = (_step = _iterator.next()).done); _iteratorNormalCompletion = true) {
        var i = _step.value;
        console.log(i);
    }
} catch (err) {
    _didIteratorError = true;
    _iteratorError = err;
} finally {
    try {
        if (!_iteratorNormalCompletion && _iterator.return) {
            _iterator.return();
        }
    } finally {
        if (_didIteratorError) {
            throw _iteratorError;
        }
    }
}

function showTextWithUnderscore(ui, text, allTime) {
    var _this = this;

    var underscore, continues, myText, setText;
    return regeneratorRuntime.async(function showTextWithUnderscore$(_context3) {
        while (1) {
            switch (_context3.prev = _context3.next) {
                case 0:
                    setText = function setText() {
                        ui.textContent = myText;
                        if (underscore) ui.textContent += "_";
                    };

                    underscore = false;
                    continues = true;
                    myText = "";


                    doWhileAsync(function () {
                        return continues;
                    }, function () {
                        underscore = !underscore;
                        setText();
                        return delayAsync(50);
                    });

                    ui.textContent = "";
                    _context3.next = 8;
                    return regeneratorRuntime.awrap(forEachAsync(text, function _callee(char) {
                        return regeneratorRuntime.async(function _callee$(_context2) {
                            while (1) {
                                switch (_context2.prev = _context2.next) {
                                    case 0:
                                        myText += char;
                                        setText();
                                        _context2.next = 4;
                                        return regeneratorRuntime.awrap(delayAsync(allTime / text.length));

                                    case 4:
                                    case "end":
                                        return _context2.stop();
                                }
                            }
                        }, null, _this);
                    }));

                case 8:
                    continues = false;

                case 9:
                case "end":
                    return _context3.stop();
            }
        }
    }, null, this);
}

function delayAsync(timeMs) {
    return new Promise(function (resolover) {
        setTimeout(function () {
            resolover();
        }, timeMs);
    });
}

function forEachAsync(range, action) {
    var i;
    return regeneratorRuntime.async(function forEachAsync$(_context4) {
        while (1) {
            switch (_context4.prev = _context4.next) {
                case 0:
                    i = 0;

                case 1:
                    if (!(i < range.length)) {
                        _context4.next = 7;
                        break;
                    }

                    _context4.next = 4;
                    return regeneratorRuntime.awrap(action(range[i]));

                case 4:
                    ++i;
                    _context4.next = 1;
                    break;

                case 7:
                case "end":
                    return _context4.stop();
            }
        }
    }, null, this);
}

function doWhileAsync(pred, action) {
    return regeneratorRuntime.async(function doWhileAsync$(_context5) {
        while (1) {
            switch (_context5.prev = _context5.next) {
                case 0:
                    if (!pred()) {
                        _context5.next = 5;
                        break;
                    }

                    _context5.next = 3;
                    return regeneratorRuntime.awrap(action());

                case 3:
                    _context5.next = 0;
                    break;

                case 5:
                case "end":
                    return _context5.stop();
            }
        }
    }, null, this);
}

function showTextIn(ui, text, allTime) {
    var _this2 = this;

    return regeneratorRuntime.async(function showTextIn$(_context7) {
        while (1) {
            switch (_context7.prev = _context7.next) {
                case 0:
                    ui.textContent = "";
                    _context7.next = 3;
                    return regeneratorRuntime.awrap(forEachAsync(text, function _callee2(char) {
                        return regeneratorRuntime.async(function _callee2$(_context6) {
                            while (1) {
                                switch (_context6.prev = _context6.next) {
                                    case 0:
                                        ui.textContent += char;
                                        _context6.next = 3;
                                        return regeneratorRuntime.awrap(delayAsync(allTime / text.length));

                                    case 3:
                                    case "end":
                                        return _context6.stop();
                                }
                            }
                        }, null, _this2);
                    }));

                case 3:
                case "end":
                    return _context7.stop();
            }
        }
    }, null, this);
}
