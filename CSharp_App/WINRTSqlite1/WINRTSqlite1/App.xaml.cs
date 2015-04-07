
using sqllite.Model;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using Windows.ApplicationModel;
using Windows.ApplicationModel.Activation;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.Storage;
using Windows.Storage.Search;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Application template is documented at http://go.microsoft.com/fwlink/?LinkId=234227

namespace WINRTSqlite1
{
    /// <summary>
    /// Provides application-specific behavior to supplement the default Application class.
    /// </summary>
    sealed partial class App : Application
    {
        public static string RecordCount = string.Empty;
        /// <summary>
        /// Initializes the singleton application object.  This is the first line of authored code
        /// executed, and as such is the logical equivalent of main() or WinMain().
        /// </summary>
        public App()
        {
            this.InitializeComponent();
            this.Suspending += OnSuspending;
        }

        /// <summary>
        /// Invoked when the application is launched normally by the end user.  Other entry points
        /// will be used when the application is launched to open a specific file, to display
        /// search results, and so forth.
        /// </summary>
        /// <param name="args">Details about the launch request and process.</param>
        protected async override void OnLaunched(LaunchActivatedEventArgs args)
        {
            Frame rootFrame = Window.Current.Content as Frame;

            // Do not repeat app initialization when the Window already has content,
            // just ensure that the window is active
            if (rootFrame == null)
            {
                // Create a Frame to act as the navigation context and navigate to the first page
                rootFrame = new Frame();

                if (args.PreviousExecutionState == ApplicationExecutionState.Terminated)
                {
                    //TODO: Load state from previously suspended application
                }

                // Place the frame in the current Window
                Window.Current.Content = rootFrame;
            }

            if (rootFrame.Content == null)
            {
                // When the navigation stack isn't restored navigate to the first page,
                // configuring the new page by passing required information as a navigation
                // parameter
                if (!rootFrame.Navigate(typeof(MainPage), args.Arguments))
                {
                    throw new Exception("Failed to create initial page");
                }
            }




            ////Sqlite3.sqlite3 db = null;
            ////////// Sqlite3.sqlite3_open( ":memory:", out db );


            ////Sqlite3.sqlite3_open(@"C:\Users\loganathan.v\Documents\devices_WPFclient\test.db", out db);
            ////Sqlite3.Vdbe stmt = null;
            ////string zero = null;
            ////string val;


            //////create table
            ////{
            ////    Sqlite3.sqlite3_prepare_v2(db, "create table Patient(PatientID varchar(140),patientName varchar(140),DOB  datetime)", -1, ref stmt, ref zero);
            ////    var r = Sqlite3.sqlite3_step(stmt);
            ////    Sqlite3.sqlite3_finalize(stmt);
            ////}

            ////Sqlite3.sqlite3_close(db);
            ////Sqlite3.sqlite3_open(@"C:\Users\loganathan.v\Documents\devices_WPFclient\test.db", out db);
            ////string val1 = string.Empty;
            ////string union = string.Empty;
            ////for (int i = 0; i < 250; i++)
            ////{

            ////    val1 += union + " Select '" + Guid.NewGuid().ToString() + "','loganathan" + i.ToString() + "','" + DateTime.Now.ToString() + "'";
            ////    union = " UNION ";
            ////    //////insert 0.1
            ////    ////{

            ////    ////    Sqlite3.sqlite3_prepare_v2(db, "insert into Patient (PatientID,patientName,DOB) values (?,?,?)", -1, ref stmt, ref zero);
            ////    ////    for (int j = 0; j < 3; j++)
            ////    ////    {
            ////    ////        if (j == 0 || j == 1)
            ////    ////            Sqlite3.sqlite3_bind_text(stmt, j, (string)"loganathan" + i.ToString(), -1, Sqlite3.SQLITE_TRANSIENT);
            ////    ////        else
            ////    ////            Sqlite3.sqlite3_bind_text(stmt, j, (Convert.ToDateTime("12/12/2012")).ToString("yyyy-MM-dd HH:mm:ss"), -1, Sqlite3.SQLITE_TRANSIENT);
            ////    ////    }
            ////    ////    Sqlite3.sqlite3_step(stmt);
            ////    ////    Sqlite3.sqlite3_finalize(stmt);

            ////    ////}
            ////}

            ////Sqlite3.sqlite3_prepare_v2(db, "insert into Patient (PatientID,patientName,DOB) " + val1, -1, ref stmt, ref zero);
            ////Sqlite3.sqlite3_step(stmt);
            ////Sqlite3.sqlite3_finalize(stmt);
            ////Sqlite3.sqlite3_close(db);

            ////////insert 0.1
            //////{
            //////    Sqlite3.sqlite3_prepare_v2(db, "insert into Test(val) values ('0.2')", -1, ref stmt, ref zero);
            //////    Sqlite3.sqlite3_step(stmt);
            //////    Sqlite3.sqlite3_finalize(stmt);
            //////}

            ////////insert 0.000000001
            //////{
            //////    Sqlite3.sqlite3_prepare_v2(db, "insert into Test(val) values ('0.000000001')", -1, ref stmt, ref zero);
            //////    Sqlite3.sqlite3_step(stmt);
            //////    Sqlite3.sqlite3_finalize(stmt);
            //////}

            //////invariant culture
            ////{

            ////    Sqlite3.sqlite3_prepare_v2(db, "select name from Test", -1, ref stmt, ref zero);
            ////    Sqlite3.sqlite3_step(stmt);
            ////    val = Sqlite3.sqlite3_column_text(stmt, 0);


            ////    Sqlite3.sqlite3_step(stmt);
            ////    val = Sqlite3.sqlite3_column_text(stmt, 0);

            ////    Sqlite3.sqlite3_step(stmt);
            ////    val = Sqlite3.sqlite3_column_text(stmt, 0);

            ////    Sqlite3.sqlite3_finalize(stmt);
            ////}

            //int index = zFilename.LastIndexOf(@"\");
            //var path = zFilename.Substring(0, index);
            //var filename = Path.GetFileName(zFilename);
            ////// To Create folder for log files.

            // Ensure the current window is active
            Window.Current.Activate();
        }

        void obj_Tick(object sender, object e)
        {

        }

        /// <summary>
        /// Invoked when application execution is being suspended.  Application state is saved
        /// without knowing whether the application will be terminated or resumed with the contents
        /// of memory still intact.
        /// </summary>
        /// <param name="sender">The source of the suspend request.</param>
        /// <param name="e">Details about the suspend request.</param>
        private void OnSuspending(object sender, SuspendingEventArgs e)
        {
            var deferral = e.SuspendingOperation.GetDeferral();
            //TODO: Save application state and stop any background activity
            deferral.Complete();
        }
    }
}
