## 15/nov

regarding log:
	1. god i need a centralized space to keep my logs. Specially when working
	from different devices and not feeling like carrying every agenda. It
	ain't often, but practical posibility.

regarding sorting:
	1. sort_three: matter of logic, nothing complicated. Think of combinations,
	the rest comes along. TBD sort_five and go into chunks.

regarding opt:
	1. is_sorted doesn't need the salad of variables it has. It is readable and
	clear, yet prone to confusion? up to me i guess. Either way, recreated a
	more compact version that alligns better visually with a typical iterator.
	2. is_sorted doesn't need to receive the data by reference. To check if 
	using raw value passing would result in optimised because of $ usage?
		2.1. may need to keep pointer as standard for uniformity in functions.
	3. chance to work around with mutability and variable ownership: const
	4. to consider: functions that iterate the stack that return pointers rather
	than index. use case specific for swap_stk
	5. Generic stack operations or specific stack based ones?
