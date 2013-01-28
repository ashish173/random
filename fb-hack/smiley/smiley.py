""" Facebook Hackathon -- Smiley Problem """

def read_file(fname):
	f = open(fname,"r")
	num = f.readline()
	number = int(num)
	f.close()	
	return number


def readf(fname, num):
	f = open(fname,"r")
	f.readline()
	for x in range(num):
		stri = f.readline()
	f.close()
	string = chop(stri)
	return string	
	

def chop(x):
	return x[:-1] 

def main():
	list1 = []
	number = read_file("smileytxt.txt")
	#list1 = chop(list1)
	#print list1
	for y in range(number):
		string = readf("smileytxt.txt", y+1)
		stack = []
		stack1 = []
		pos = []
		#print string
		for x in range(len(string)):
			key = string[x]
			if key in [' ', ""] or key.isalpha():
				pass
			elif string[x]==':' and (string[x+1]==')' or string[x+1]=='('):
				pos.append(x)		 
			elif string[x]==':':
				pass
			elif key=='(':
				stack.append(key)
			elif key==')':
				#if string[x-1]==':':
				#	pass
				stack1.append(key)
				if not stack and not pos:
					print "case #", y+1, " NO"
					return 
				if stack:
					stack.pop()
			else:
				print 'try agian'
		if (len(stack) == len(pos)) or (len(stack) == len(stack1)):
			print "case #", y+1, " YES"		
		elif stack:
			print "case #", y+1, " NO"		
		elif not stack:
			print "case #", y+1, " YES"
			


if __name__ == "__main__":
	main()
