import unittest

def sum_list_numbers(list1, list2):
	# list1 and list2 must be array or tuple
	# the question says "LinkedList" is passed to method but there is no implementation in python, so I use list as linked list
	
	if list1 is None or list2 is None: return None
	
	result = [] # result linked list
	idx = 0
	carry = 0
	
	len1 = len(list1)
	len2 = len(list2)
	
	while idx < len1 or idx < len2:
		num1 = list1[idx] if idx < len1 else 0
		num2 = list2[idx] if idx < len2 else 0
		if num1 < 0 or num1 >= 10: return None # invalid element
		if num2 < 0 or num2 >= 10: return None # invalid element
		ret = num1 + num2 + carry
		
		result.append(ret%10)
		carry = ret//10
		idx += 1
	
	if carry != 0:
		result.append(carry)
	
	return result
	
	
class Test(unittest.TestCase):
	def test_sumlist(self):
		list1 = [7,1,6]
		list2 = [5,9,2]
		self.assertEqual([2,1,9], sum_list_numbers(list1, list2))
		
		list1 = [7,1]
		list2 = [9,8,2,0,1]
		self.assertEqual([6,0,3,0,1], sum_list_numbers(list1, list2))
		
		list1 = [7,1]
		list2 = [9,8,9]
		self.assertEqual([6,0,0,1], sum_list_numbers(list1, list2))
		
		list1 = []
		list2 = [9,8,9]
		self.assertEqual([9,8,9], sum_list_numbers(list1, list2))
		
		list1 = None
		list2 = [9,8,9]
		self.assertEqual(None, sum_list_numbers(list1, list2))
		
		list1 = [-1,1]
		list2 = [9,8,9]
		self.assertEqual(None, sum_list_numbers(list1, list2))
		
		list1 = [10,1]
		list2 = [9,8,9]
		self.assertEqual(None, sum_list_numbers(list1, list2))
				
if __name__ == "__main__":
	unittest.main()
	