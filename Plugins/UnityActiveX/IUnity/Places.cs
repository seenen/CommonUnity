using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace IUnity
{
    [Guid("F34B51BB-2808-42A6-B5C8-9A6CA8FA8719")]
    public static class Places
    {
        private static List<String> _ListPlaces = new List<string>();
        public static List<String> ListPlaces
        {
            get
            {
                return _ListPlaces;
            }
            set
            {
                _ListPlaces = value;
            }
        }



        public static void AddPlace(string namePlace)
        {
            ListPlaces.Add(namePlace);
        }
    }
}
