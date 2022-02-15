// WAP to identify whether a given line is a comment or not.

let str = "/*Hello World*/";
let cs = false;

if (str[0] === "/") {
	if (str[1] === "/") {
		console.log("This is a single line comment.");
		cs = true;
	} else if (str[1] === "*") {
		for (let i = 2; i < str.length; i++) {
			if (str[i] === "*" && str[i + 1] === "/") {
				console.log("This is a multiline comment.");
				cs = true;
				break;
			}
		}
	}
}

if (!cs) console.log("This is not a comment.");
