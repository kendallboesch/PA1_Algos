#include <iostream>

class C1 {

   public:

   static int compareCount;

   C1()
   {
     for (int i = 0; i < 3; i++)
	arr[i] = 0;
   }
    
   
   C1(int a, int b, int c)
	{
           arr[0] = a;
           arr[1] = b;
           arr[2] = c;
	}

   C1 (const C1&  t)
   {
     for (int i = 0; i < 3; i++)
	arr[i] = t.arr[i];
      
   }

   C1 & operator==(const C1& t)
   {
     for (int i = 0; i < 3; i++)
	arr[i] = t.arr[i];
     return *this;

   }

   bool operator<(const C1& t)
   {
      compareCount++;
      //std::cout << compareCount << std::endl;
      if (arr[0] < t.arr[0])
         return true;
      else if (arr[0] == t.arr[0])
		{
		      if (arr[1] < t.arr[1])
			 return true;
		      else if ((arr[1] == t.arr[1]) && (arr[2] < t.arr[2]))
			 return true;

		}
      return false;
   }


   void Print()
   {
     std::cout << "[ ";
     for (int i = 0; i < 3; i++)
	 std::cout << arr[i] << " ";
     std::cout <<"]";

   }

  
   private:
    int arr[3];

};

int C1::compareCount = 0;
