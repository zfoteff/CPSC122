#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
 public:

   /*
   Pre: strIn is C-String
   Post: An instance of MyString is created and set to the contents of strIn
   */
   MyString(char const* strIn);

   /*
   Pre: none
   Post: returns dynamically allocated memory to the heap
   */
   ~MyString();

   /*
   Pre: an instance of MyString exists
   Post: Contents of the instance of myString is displayed on the screen
   */
   void MyStrDisplay();

   /*
   Pre: An instance of MyString exists
   Post: Number of characters in the instance of MyString, excluding
         the null character is returned
   */
   int MyStrlen();

   /*
   Pre: an instance of MyString exists whose lengthe <= length of strIn
   Post: the contents of strIn overwrites the contentw of the instance
         of MyString
   */
   void MyStrcpy(char const* strIn);

   /*
   Pre: an instance of MyString exists
   Post: Compares *this with the argument lexicograpically. Returns
         -1 if *this would appear before *strIn
          0 if the strings are the same
          1 if *this would appear after *strIn
   */
   int MyStrcmp(char const* strIn);

   /*
   Pre: an instance of MyString exists
   Post: if strIn is a substring of the instance of MyString, returns
         its starting positon, -1 otherwise
   */


   int Find(char const* strIn);

 private:
   char* str;
};
#endif
