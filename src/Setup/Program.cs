using System;
using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;

namespace Setup
{
    class Program
    {
        static void Main(string[] args)
        {
            var installers = new[]{
                "KBFRZ71_i386.msi",
                "KBFRZ71_amd64.msi",
            };

            var index = Is64Bit() ? 1 : 0;

            MsiExec(installers[index]);
        }

        private static void MsiExec(string name)
        {
            var package = GetFullPath(name);
            if (package == null)
                return;

            const string command = "msiexec.exe";
            var options = $"/i \"{package}\"";

            Process.Start(
                new ProcessStartInfo
                {
                    FileName = command,
                    Arguments = options,
                    CreateNoWindow = true,
                    UseShellExecute = false,
                }
                );
        }

        private static string GetFullPath(string fileName)
        {
            var directory = GetWorkingDirectory();
            if (directory == null)
                return null;

            var path = Path.Combine(directory, fileName);
            return path;

        }

        private static string GetWorkingDirectory()
        {
            var directory = System.Reflection.Assembly.GetExecutingAssembly().Location;
            if (directory != null)
                directory = Path.GetDirectoryName(directory);
            return directory;
        }

        #region

        [DllImport("kernel32.dll", SetLastError = true, CallingConvention = CallingConvention.Winapi)]
        [return: MarshalAs(UnmanagedType.Bool)]
        public static extern bool IsWow64Process([In] IntPtr hProcess, [Out] out bool lpSystemInfo);

        private static bool Is64Bit()
        {
            if (IntPtr.Size == 8 || (IntPtr.Size == 4 && Is32BitProcessOn64BitProcessor()))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        private static bool Is32BitProcessOn64BitProcessor()
        {
            bool retVal;

            IsWow64Process(Process.GetCurrentProcess().Handle, out retVal);

            return retVal;
        }

        #endregion
    }
}
