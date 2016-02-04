using CommonUnity.CommandLine;
using System;

namespace CommonUnity
{
    class Program
    {
        static Demo mDemo = null;

        static void Main(string[] args)
        {
            var arguments = CommandLineArgumentParser.Parse(args);

            mDemo = new Demo();
            mDemo.Load();

            string line;
            Console.WriteLine("Enter one or more lines of text (press CTRL+Z to exit):");
            Console.WriteLine();
            do
            {
                Console.Write("   ");
                line = Console.ReadLine();
                if (line != null)
                    Console.WriteLine("      " + line);
            } while (line != null);

            mDemo.Unload();
            mDemo = null;
        }
    }
}
