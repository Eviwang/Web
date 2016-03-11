"use strict";

var ui1 = document.getElementById("ui1");
var ui2 = document.getElementById("ui2");
var ui3 = document.getElementById("ui3");
var ui4 = document.getElementById("ui4");

showTextIn(ui1, "[A]: This line will display in 1 second.", 1000).then(function () {
    showTextIn(ui3, "[C]: This line will appears after [A] appears.", 1000);
});
showTextIn(ui2, "[B]: this line will latest for 2 seconds.", 2000);

showTextWithUnderscore(ui4, "[D]: this line underscore flashes.", 3000);

function *test() {
    for (let i = 0; i < 10; ++i) {
        yield i;
    }
}
for (let i of test()) console.log(i);

async function showTextWithUnderscore(ui, text, allTime) {
    var underscore = false;
    var continues = true;
    var myText = "";

    function setText() {
        ui.textContent = myText;
        if (underscore) ui.textContent += "_";
    }

    doWhileAsync(() => continues, () => {
        underscore = !underscore;
        setText();
        return delayAsync(50);
    });

    ui.textContent = "";
    await forEachAsync(text, async (char) => {
        myText += char;
        setText();
        await delayAsync(allTime / text.length);
    });
    continues = false;
}

function delayAsync(timeMs) {
    return new Promise((resolover) => {
        setTimeout(() => {
            resolover();
        }, timeMs);
    });
}

async function forEachAsync(range, action) {
    for (let i = 0; i < range.length; ++i) {
        await action(range[i]);
    }
}

async function doWhileAsync(pred, action) {
    while (pred()) {
        await action();
    }
}

async function showTextIn(ui, text, allTime) {
    ui.textContent = "";
    await forEachAsync(text, async (char) => {
        ui.textContent += char;
        await delayAsync(allTime / text.length);
    });
}