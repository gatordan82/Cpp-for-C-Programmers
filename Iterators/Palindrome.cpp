#include <string>
#include <iostream>

template <typename Bidirectional>
bool isPalindrome(Bidirectional first, Bidirectional last)
{
	while (true)
	{
		last--;
		if (first == last)
			break;
		if (*first != *last)
			return false;

		first++;
		if (first == last)
			break;
	}

	return true;
}

//int main()
//{
//	using namespace std;
//
//	string palindrome{ "lool" };
//	string nonPalindrome{ "hello" };
//
//	cout << "Is " << palindrome << " a string?" << endl;
//	cout << boolalpha 
//		 << isPalindrome(palindrome.begin(), palindrome.end()) 
//		 << "\n\n";
//
//	cout << "Is " << nonPalindrome << " a string?" << endl;
//	cout << boolalpha
//		<< isPalindrome(nonPalindrome.begin(), nonPalindrome.end())
//		<< "\n\n";
//
//	cin.get();
//	cin.get();
//
//	return 0;
//
//}