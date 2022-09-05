using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using Newtonsoft.Json;

namespace Histo
{
    class Program
    {
        static int ReadInteger(string prompt, int min, int max)
        {
            Console.WriteLine(prompt);
            string input = Console.ReadLine();
            int num = 0;
            if (int.TryParse(input, out int result) == true && result > min && result < max + 1)
            {
                num = result;
            }
            else
            {
                Console.WriteLine("Please enter a valid number!");
                string mew = Console.ReadLine();
                input = mew;
            }
            return num;
        }
        static void ReadString(string prompt, ref string value)
        { 
            Console.WriteLine(prompt);
            string input = Console.ReadLine();
            while (string.IsNullOrWhiteSpace(input))
            {
                Console.WriteLine("There is nothing there! Try again.");
                input = Console.ReadLine();
            }
            value = input;
        }
        static void ReadChoice(string prompt, string[] choices, out int chose)
        {
            for (int i = 0; i < choices.Length; i++)
            {
                Console.WriteLine(choices[i]);
            }
            chose = ReadInteger(prompt, 0, choices.Length);
        }
        static string GetSpeech()
        {
            string text = "I say to you today, my friends, so even though we face the difficulties of today and tomorrow, I still have a dream. It is a dream deeply rooted in the American dream. " +
            "I have a dream that one day this nation will rise up and live out the true meaning of its creed: We hold these truths to be self-evident: that all men are created equal. " +
            "I have a dream that one day on the red hills of Georgia the sons of former slaves and the sons of former slave owners will be able to sit down together at the table of brotherhood. " +
            "I have a dream that one day even the state of Mississippi, a state sweltering with the heat of injustice, sweltering with the heat of oppression, will be transformed into an oasis of freedom and justice. " +
            "I have a dream that my four little children will one day live in a nation where they will not be judged by the color of their skin but by the content of their character. " +
            "I have a dream today. I have a dream that one day, down in Alabama, with its vicious racists, with its governor having his lips dripping with the words of interposition and nullification; one day right there in Alabama, little black boys and black girls will be able to join hands with little white boys and white girls as sisters and brothers. " +
            "I have a dream today. I have a dream that one day every valley shall be exalted, every hill and mountain shall be made low, the rough places will be made plain, and the crooked places will be made straight, and the glory of the Lord shall be revealed, and all flesh shall see it together. " +
            "This is our hope. This is the faith that I go back to the South with. With this faith we will be able to hew out of the mountain of despair a stone of hope. With this faith we will be able to transform the jangling discords of our nation into a beautiful symphony of brotherhood. " +
            "With this faith we will be able to work together, to pray together, to struggle together, to go to jail together, to stand up for freedom together, knowing that we will be free one day. " +
            "This will be the day when all of God's children will be able to sing with a new meaning, My country, 'tis of thee, sweet land of liberty, of thee I sing. Land where my fathers died, land of the pilgrim's pride, from every mountainside, let freedom ring. " +
            "And if America is to be a great nation this must become true. So let freedom ring from the prodigious hilltops of New Hampshire. Let freedom ring from the mighty mountains of New York. Let freedom ring from the heightening Alleghenies of Pennsylvania! " +
            "Let freedom ring from the snowcapped Rockies of Colorado! Let freedom ring from the curvaceous slopes of California! But not only that; let freedom ring from Stone Mountain of Georgia! " +
            "Let freedom ring from Lookout Mountain of Tennessee! Let freedom ring from every hill and molehill of Mississippi. From every mountainside, let freedom ring. " +
            "And when this happens, when we allow freedom to ring, when we let it ring from every village and every hamlet, from every state and every city, we will be able to speed up that day when all of God's children, black men and white men, Jews and Gentiles, Protestants and Catholics, will be able to join hands and sing in the words of the old Negro spiritual, Free at last! free at last! thank God Almighty, we are free at last!";

            return text;
        }
        static string GetSpeechFromFile()
        {
            string file = "speech.csv";
            using (StreamReader read = new StreamReader(file))
            {
                return read.ReadToEnd();
            }
    }
        static void Main(string[] args)
        {
            string spec = GetSpeechFromFile();
            char[] delim = new char[] { ' ', '.', ',', '!', ':', ';', '"' };
            string[] speech = spec.Split(delim, StringSplitOptions.RemoveEmptyEntries);
            char[] sen = new char[] { '.', '!' };
            string[] sent = spec.Split(sen);
            List <string> spee = speech.ToList();
            Dictionary<string, int> spval = new Dictionary<string, int>();
            
            foreach(string value in spee)
            {
                if(spval.ContainsKey(value))
                {
                    spval[value]++;
                }
                else
                {
                    spval.Add(value, 1);
                }
            }
            int choice = 0;
            
            while(choice != 6)
            {
                string[] opt = new string[6] { "1. Show Histogram", "2. Search Histogram", "3. Save Histogram", "4. Load Histogram", "5. Remove Word", "6. Exit." };
            ReadChoice("What do you wanna do?", opt, out choice);
                if(choice == 1)
                {
                    foreach(KeyValuePair<string, int> key in spval)
                    {
                        Console.Write(key.Key);
                        Console.CursorLeft = 15;
                        Console.BackgroundColor = ConsoleColor.Magenta;
                        for (int i = 0; i < key.Value; i++)
                        {
                            Console.Write(" ");
                        }
                        Console.BackgroundColor = ConsoleColor.Black;
                        Console.WriteLine(key.Value);
                    }
                    Console.WriteLine("\n Press any key.");
                    Console.ReadKey();
                    Console.Clear();
                    ReadChoice("What do you wanna do now?", opt, out choice);
                }
                if(choice == 2)
                {
                    Console.WriteLine("What word do you wanna find?");
                    string input = Console.ReadLine();
                    if(spval.ContainsKey(input))
                    {
                        Console.Write(input);
                        bool val = spval.TryGetValue(input, out int mio);
                        Console.CursorLeft = 15;
                        Console.BackgroundColor = ConsoleColor.Magenta;
                        for (int i = 0; i < mio; i++)
                        {
                            Console.Write(" ");
                        }
                        Console.BackgroundColor = ConsoleColor.Black;
                        Console.WriteLine(mio);
                        for (int i = 0; i < sent.Length; i++)
                        {
                            string[] vs = sent[i].Split(delim, StringSplitOptions.RemoveEmptyEntries);
                            foreach(string va in vs)
                            {
                                int tru = string.Compare(va, input, true);
                                if(tru == 0)
                                {
                                    Console.WriteLine(sent[i]);
                                }
                            }

                        }
                    }
                    else
                    {
                        Console.WriteLine(" "+ input+" not found.");
                    }
                    Console.WriteLine("\n Press any key.");
                    Console.ReadKey();
                    Console.Clear();
                    ReadChoice("What do you wanna do now?", opt, out choice);
                }
                else if(choice == 3)
                {
                    string filnam = "";
                    ReadString("What do you wanna name your file?", ref filnam);
                    string type = Path.GetExtension(filnam);
                    filnam = Path.ChangeExtension(filnam, ".json");

                    using(StreamWriter save = File.CreateText(filnam))
                    {
                        using(JsonTextWriter jtw = new JsonTextWriter(save))
                        {
                            jtw.Formatting = Formatting.Indented;
                            JsonSerializer create = new JsonSerializer();
                            create.Serialize(jtw, spval);
                        }
                    }
                    Console.WriteLine("\n Press any key.");
                    Console.ReadKey();
                    Console.Clear();
                    ReadChoice("What do you wanna do now?", opt, out choice);
                }
                else if(choice == 4)
                {
                    string fil2 = "";
                    ReadString("What file are we loading?", ref fil2);
                    if(File.Exists(fil2))
                    {
                        using (StreamReader readit = new StreamReader(fil2))
                        {
                            string filtex = readit.ReadToEnd();
                            spval = JsonConvert.DeserializeObject<Dictionary<string, int>>(filtex);
                        }
                    }
                    else
                    {
                        ReadString("Please try again", ref fil2);
                    }
                    Console.WriteLine("\n Press any key.");
                    Console.ReadKey();
                    Console.Clear();
                    ReadChoice("What do you wanna do now?", opt, out choice);
                }
                else if(choice == 5)
                {
                    string rem = "";
                    ReadString("What word would you like to remove?", ref rem);
                    bool move = spval.Remove(rem);
                    if(rem == null)
                    {
                        ReadString("Please enter something to remove.", ref rem);
                    }
                    else if(move == false)
                    {
                        ReadString("" + rem + " was not found.  Try again.", ref rem);
                    }
                    Console.WriteLine("\n Press any key.");
                    Console.ReadKey();
                    Console.Clear();
                    ReadChoice("What do you wanna do now?", opt, out choice);
                }

            }
            if (choice == 6)
            {
                System.Environment.Exit(0);
            }
        }
    }
}
