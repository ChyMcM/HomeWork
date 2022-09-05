using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_9A
{
    public class Submission
    {
        public static Student[] enrollment = new Student[0];

        public static Student Test1(string last, string first, int idNo)
        {
            Student ran = new Student(last, first, idNo);
            return ran;
        }

        public static Student Test2()
        {
            Student rio = new Student();
            return rio;
        }

        public static bool Test3(Student enrolled)
        {
            bool riz = false;
            for(int rye = 0; rye < enrollment.Length; rye++)
            {
                if(enrollment[rye] != null)
                {
                    riz = false;
                }
                else
                {
                    enrollment[rye] = enrolled;
                    riz = true;
                    break;
                }
            }
            return riz;
        }

        public static bool Test4(int idNumber)
        {
            bool neo = false;
            for(int mio = 0; mio < enrollment.Length; mio++)
            {
                if(enrollment[mio] == null)
                {
                }
                else if(enrollment[mio].GetIDNumber() == idNumber)
                {
                    enrollment[mio] = null;
                    neo = true;
                    break;
                }
                
                else if(enrollment[mio].GetIDNumber() != idNumber)
                {
                    neo = false;
                }
            }
            return neo;
        }

        public static Student Test5(int idNumber)
        {
            Student stu = null;
            for(int ki = 0; ki < enrollment.Length; ki++)
            {
                if(enrollment[ki] == null)
                {
                }
                else if (enrollment[ki].GetIDNumber() == idNumber)
                {
                    stu = enrollment[ki];
                    break;
                }
            }
            return stu;
        }
    }
}
