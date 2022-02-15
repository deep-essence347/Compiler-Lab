// WAP to simulate DFA for the language over Σ= {0, 1} starting with 1 and ending with 0.
let transition = [];
let accepted = false;

function q0(str, i) {
	transition.push("q0");
	if (i === str.length) return;

	if (str[i] === "0") q3(str, i + 1);
	else q1(str, i + 1);
}

function q1(str, i) {
	transition.push("q1");
	if (i === str.length) return;

	if (str[i] === "0") q2(str, i + 1);
	else q1(str, i + 1);
}

function q2(str, i) {
	transition.push("q2");
	if (i === str.length) {
		accepted = true;
		return;
	}

	if (str[i] === "0") q2(str, i + 1);
	else q1(str, i + 1);
}

function q3(str, i) {
	return;
}

let str = "1011010";
q0(str, 0);

if (accepted) console.log(`State Transition: ${transition.join(" -> ")}`);
else console.log("The string is rejected");
