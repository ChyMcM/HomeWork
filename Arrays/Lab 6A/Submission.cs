using System;
using System.Diagnostics.Contracts;
using Tester;

namespace FSPG1
{
    class Submission
    {
        /*
         * This lab is NOT interactive - that means there should be no 
         * calls to the Console class (no Write/WriteLine/ReadLine/ReadKey)
         * 
         * You cannot use multiple return statements any of these methods. 
         * Additionally the use of var is not permitted
         * 
        */

        // Test 1 – Convert char array to int array
        // Given an array of char, phrase, convert each element to an
        // equivalent int value and place in an int array.
        // Return the int array
        public static int[] Test1(char[] phrase)
        {
            int[] vs = new int[phrase.Length];
            for(int e = 0; e < phrase.Length; e++)
            {
                vs[e] = phrase[e];
            }
            return vs;
        }

        // Test 2 - Array statistics
        // Given an array of double, data, find the smallest element, 
        // the largest element and the numeric mean (average). Store the 
        // results in an array (in that order: smallest, largest, mean).
        // Return the array
        public static double[] Test2(double[] data)
        {
            double max = data[0];
            double min = data[0];
            foreach(double value in data)
            {
                if(value < min)
                {
                    min = value;
                }
                else if(value > max)
                {
                    max = value;
                }
            }
            double sum = 0;
            for(int lulu = 0; lulu < data.Length; lulu++)
            {
                sum += data[lulu];
            }
            double av = sum / data.Length;
            double[] neeko = { min, max, av };
            return neeko;
        }

        // Test 3 - Normalize an array (of double)
        // Given an array of double, numbers, normalize the array. To 
        // normalize an array:
        // 1) Find the largest element stored in the array
        // 2) Divide each element in the array by the largest value
        //    and replace each array element with the result of the 
        //    division.
        // Since the array's contents are being modified, there is 
        // nothing to return
        public static void Test3(double[] numbers)
        {
            double max = numbers[0];
            foreach(double value in numbers)
            {
                if(value > max)
                {
                    max = value;
                }
            }
            for(int u = 0; u < numbers.Length; u++)
            {
                numbers[u] = numbers[u] / max;
            }
        }

        // Test 4 - Uniqueness
        // Given an array of string, names, verify that each name is unique
        // mean that none of the names are duplicated within the array.
        // If the array is unique, return true; otherwise, return false
        public static bool Test4(string [] names)
        {
            bool uni = true;
            for(int mojo = 0; mojo < names.Length - 1; mojo++)
            {
                for(int jojo = mojo + 1; jojo < names.Length; jojo++)
                {
                    if(names[mojo] == names[jojo])
                    {
                        uni = false;
                    }
                }
            }

            return uni;
        }

        // Test 5 - Acronym
        // Given an array of string, words, create a string that is the 
        // acronym (first letter of each word). Return the string
        public static string Test5(string [] words)
        {
            string neo = "";
            for(int mio = 0; mio < words.Length; mio++)
            {
                neo += words[mio][0];
            }
            return neo;
        }

        // Test 6 - Array reverse
        // Given a char array, letters, create another array that has the
        // same elements but in reverse order. Return the array
        // 
        // You are not allowed to use Array.Reverse (or any existing
        // method) to reverse the array
        //
        public static char[] Test6(char[] letters)
        {
            char[] rev = new char[letters.Length];
            int ek = 0;
            for(int eh = letters.Length - 1; eh >= 0; eh--)
            {
                rev[ek] = letters[eh];
                ek++;
            }
            return rev;
        }

        // Test 7 - Transpose array
        // Given a 2-Dimension array of int, table, create a new array that 
        // 'transposes' the original array. Transposing means that each row 
        // in the original array will be a column in the new array and each
        // column in the original array will be a row in the new array.
        // For example, given
        //   4   3   1   5
        //   2   7   0   8
        //
        // The transposed array would be
        //   4   2
        //   3   7
        //   1   0
        //   5   8
        //
        public static int[,] Test7(int [,] table)
        {
            int row = table.GetLength(0);
            int col = table.GetLength(1);
            int[,] bw = new int[col, row];
            for(int erm = 0; erm < row; erm++)
            {
                for (int er = 0; er < col; er++)
                    bw[er, erm] = table[erm, er];
            }
            return bw;
        }

        // Test 8 – Return a 2D array
        // Given three arrays of the same type (int) and size, combine the 
        // arrays into a single 2D array. Return the 2D array
        // NOTE: This solution requires a single loop (not three)
        // 
        public static int [,] Test8(int [] mins, int [] maxes, int [] seeds)
        {
            int[,] d2 = new int[3, mins.Length];
            for(int um = 0; um < mins.Length; um++)
            {
                d2[0, um] = mins[um];
                d2[1, um] = maxes[um];
                d2[2, um] = seeds[um];
            }
            return d2;
        }

        // Test 9 – Convert int array to char array
        // Given an array of int, ascii, convert each element to an
        // equivalent char value and place in a char array.
        // Return the char array
        public static char[] Test9(int[] ascii)
        {
            char[] shi = new char[ascii.Length];
            for(int i = 0; i < ascii.Length; i++)
            {
                shi[i] = (char)ascii[i];
            }
            return shi;
        }

        // Test 10 – Modify an existing array
        // Given an array of char (all uppercase), modify the array so
        // that every other element will be lowercase (even indexes are 
        // upper, odd indexes are lower)
        public static void Test10(char[] word)
        {
            for(int m = 0; m < word.Length; m++)
            {
                if(m % 2 != 0)
                {
                    word[m] = char.ToLower(word[m]);
                }
            }
        }
    }
}
