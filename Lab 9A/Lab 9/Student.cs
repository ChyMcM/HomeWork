using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_9A
{
    public class Student
    {
        // Add member fields here
        private string fir;
        private string las;
        private int idnum;

        // Add default and overloaded constructors here
        public Student()
        {
            fir = "";
            las = "";
            idnum = 1000000;
        }
        public Student(string last, string first, int idNo)
        {
            las = last;
            fir = first;
            idnum = idNo;
        }
        

        // add Getters and Setters here
        public string GetLastName()
        {
            return las;
        }
        public string GetFirstName()
        {
            return fir;
        }
        public int GetIDNumber()
        {
            return idnum;
        }
        public void SetLastName(string last)
        {
            las = last;
        }
        public void SetFirstName(string first)
        {
            fir = first;
        }
        public void SetIDNumber(int idn)
        {
            idnum = idn;
        }























/******************************************************************************************************
*                                                                                                     *
*                                                                                                     *
*                                                                                                     *
*                                                                                                     *
*                      do not modify any of the following code                                        *
*                                                                                                     *
*                                                                                                     *
*                                                                                                     *
*                                                                                                     *
*                                                                                                     *
******************************************************************************************************/
        public override string ToString()
        {
            return "ID #: " + GetIDNumber() + "\tName: " + GetLastName() + ", " + GetFirstName();
        }

        public override bool Equals(object obj)
        {
            bool same = true;
            Student s2 = (Student)obj;
            if (this.GetLastName() != s2.GetLastName() || this.GetFirstName() != s2.GetFirstName() || this.GetIDNumber() != s2.GetIDNumber())
            {
                same = false;
            }
            return same;
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }
    }
}
