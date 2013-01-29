"""   FACEBOOK HACKER CUP :- BEAUTIFUL STRING """

def read_file(fname):
    	f = open(fname,"r")
    	num = f.readline()
    	number = int(num)
    	list_string = []
    	for x in range(number):
			list_string.append(f.readline())
    	return list_string

def remo(map1):
	if ' ' in map1:
		del(map1[' '])
	if '\n' in map1:	
		del(map1['\n'])
	return map1


def main():
    list1 = []
    list1 = read_file("st.txt")
    for x in range(len(list1)):
		map1 = {}
		string = list1[x]
		for y in range(len(string)):
			key = string[y].lower()
			if key.isalpha():
				if key in map1:
					map1[key] = (map1[key]) + 1
				else:
					map1[key] = 1
		map1 = remo(map1)
		#print map
		sort_list = sorted(map1, key=map1.__getitem__, reverse=True)
		#print sort_list
		y=0
		sum1 = 0
		for x in reversed(range(27-len(sort_list), 27)):
			sum1 += x * map1[sort_list[y]]
			y = y+1
		print "case #",y,' :', sum1	 						 
				

if __name__ == "__main__":
	    main()

