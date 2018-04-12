#include <stack>
#include <cassert>

using namespace std;

template <typename T>
stack<T> sort_stack(const stack<T> &orig_stack)
{
	stack<T> orig = orig_stack;
	
	stack<T> stack_small, stack_large;
		
	// move small numbers to stack_small. on the other hand, to stack_large
	while (!orig.empty())
	{
		T top = orig.top();
		orig.pop();
		if (stack_small.empty()) {
			stack_small.push(top);
			continue;
		}
		
		T small_top = stack_small.top();
		if (top <= small_top) {
			stack_small.push(top);
		}
		else {
			stack_large.push(top);
		}
	}
	
	// if stack_large is empty, stack_small is already sorted
	if (stack_large.empty()) return stack_small;
	
	// move numbers from two stack to orig in descendant order
	while (!stack_small.empty())
	{
		T small_top = stack_small.top();

		if (stack_large.size() != 0)
		{
			T large_top = stack_large.top();
			if (small_top < large_top)
			{
				orig.push(stack_small.top());
				stack_small.pop();
			}
			else
			{
				orig.push(stack_large.top());
				stack_large.pop();
			}
		}
		else
		{
			orig.push(stack_small.top());
			stack_small.pop();
		}
	}
	
	// merge sorted
	while (!orig.empty()) {
		stack_large.push(orig.top());
		orig.pop();
	}
	auto ret = stack_large;
	while (!stack_large.empty()) {
		stack_large.pop();
	}
	
	return ret;
}

void main()
{
	stack<int> case1;
	case1.push(2); case1.push(5); case1.push(1); case1.push(1); case1.push(3);
	auto sorted = sort_stack(case1);
	
	assert (1 == sorted.top()); sorted.pop();
	assert (1 == sorted.top()); sorted.pop();
	assert (2 == sorted.top()); sorted.pop();
	assert (3 == sorted.top()); sorted.pop();
	assert (5 == sorted.top()); sorted.pop();
	assert (sorted.empty());

	stack<int> case2;
	sorted = sort_stack(case2);
	assert (sorted.empty());
}

