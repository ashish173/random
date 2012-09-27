#!/usr/bin/python

# a is the list
def bin(a,key):
	size = len(a) 	
	half_size = size/2
#	print half_size
	if size < 0:
		return "search not found"
	if a[half_size] == key:
		return "search is found at", half_size
	elif a[half_size] < key:
		print "mid index-->", half_size," mid_element--> ",a[half_size], "new list-->", a
		bin(a[half_size:], key)
	elif a[half_size] > key:
		print "mid index-->", half_size," mid element--> ", a[half_size], "new list-->", a
		bin(a[:half_size], key)
	else:
		print "search not found"


def main():
	a = [6, 3, 10, 24, 2, 1, 30, -5] # input list
	bin(a,24)
	

if __name__  == "__main__":
	main()
	
