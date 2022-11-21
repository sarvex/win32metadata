using System;

namespace Windows.Win32.Interop
{
    public class RAIIFreeAttribute : Attribute
    {
        public RAIIFreeAttribute(Type type, string name)
        {
            this.Type = type;
            this.Name = name;
        }

        /// <summary>Gets the containing class for the CloseApi.</summary>
        public Type Type { get; }

        /// <summary>Gets the name of the CloseApi.</summary>
        public string Name { get; }
    }
}
