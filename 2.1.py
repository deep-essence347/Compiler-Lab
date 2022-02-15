def transition(cs: int, e: str):
	if cs == 1:
		return 2 if e =='a' else 4 
	if cs == 2 or cs == 3:
		return 3 if e == 'a' else 5
	if cs == 4:
		return 6 if e == 'a' else 5
	if cs == 5:
		return 0 if e == 'a' else 5
	if cs == 6:
		return 0 if e == 'a' else 7
	if cs == 7:
		return 0 if e == 'a' else 8

def recognized (string: str) -> bool:
	cs = 1
	while len(string) and not cs == 0:
		cs = transition(cs, string [0])
		string = string[1:]
	return True if [2, 4, 5, 8].count(cs) else False

string = input("Enter a string: ")
hasRecognized: bool= recognized(string)
print("The string is recognized." if hasRecognized else "The string is not recognized")
