using System;
using System.Collections.Generic;

namespace CJSH
{
    class program
    {
        static void Main(string[] args)
        {
            List<string> userInput = new List<string>();
            while (true)
            {
                string prompt = "PLACEHOLDER: ";
                Console.Write(prompt);
                userInput = fetchTokens(Console.ReadLine());

                foreach (string i in userInput)
                {
                    Console.WriteLine(i);
                }

                if (userInput[0] == "exit")
                {
                    Console.WriteLine("Goodbye");
                    break;
                }
            }
        }

        // Converts a string into a list of string tokens
        public static List<string> fetchTokens(string str)
        {
            List<string> output = new List<string>();
            output.AddRange(str.Split(" "));

            // Need to prevent splits inside quotes and after "\"

            return output;
        }
    }   
}

