let creatorNames = document.getElementById("creators-numbered-list").textContent.split('\n');
creatorNames = creatorNames.map(element => {
    return element.trim();
});

let namesAndSurnames = []
for (let i = 0; i < creatorNames.length; i++) {
    namesAndSurnames.push({fullName: creatorNames[i], surname: getSurname(creatorNames[i])});
}

namesAndSurnames.sort((a, b) => (a.surname > b.surname) ? 1 : -1)

for (let i = 0; i < creatorNames.length; i++) {
    let name = namesAndSurnames[i].fullName;
    let link = makeHyperlink(name);
    creatorNames[i] = i+1 + ". " + link;
}

document.getElementById("creators-numbered-list").innerHTML = creatorNames.join('<br>');

function getSurname(name) {
    if (name === "Fuck Theory")
        return "Fuck";
    if (name === "Gabriel García Márquez")
        return "García Márquez";
    return name.split(" ").slice(-1).toString();
}

function makeHyperlink(name) {
    let htmlSafeName = name.replaceAll(' ', '_');
    let before = String.raw`<a href="`;
    let between = String.raw`.html">`;
    let after = String.raw`</a>`;
    return before + htmlSafeName + between + name + after;
}
