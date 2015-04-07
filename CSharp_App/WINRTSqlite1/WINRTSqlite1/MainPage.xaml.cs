
using WINRTSqlite3;
using sqllite.Model;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.Graphics.Imaging;
using Windows.Media.Capture;
using Windows.Storage;
using Windows.Storage.BulkAccess;
using Windows.Storage.FileProperties;
using Windows.Storage.Search;
using Windows.Storage.Streams;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Media.Imaging;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

namespace WINRTSqlite1
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        SQLiteAsyncConnection connection;
        public MainPage()
        {
            this.InitializeComponent();

        }

        /// <summary>
        /// Invoked when this page is about to be displayed in a Frame.
        /// </summary>
        /// <param name="e">Event data that describes how this page was reached.  The Parameter
        /// property is typically used to configure the page.</param>
        protected override void OnNavigatedTo(NavigationEventArgs e)
        {

        }



        #region Sqlite operation
        private async void btnBulkInsert_Click(object sender, RoutedEventArgs e)
        {
            var Dbpath = await KnownFolders.DocumentsLibrary.CreateFolderAsync("DBFile", CreationCollisionOption.OpenIfExists);
            connection = new SQLiteAsyncConnection(string.Format("{0}\\{1}", Dbpath.Path, "Sqlitedb.db"));

            ////Create table
            connection.CreateTableAsync<User>();

            var listUser = new List<User>();
            listUser.Add(new User() { UserID = Guid.NewGuid(), DOB = DateTime.Now, Name = "senthil" });
            listUser.Add(new User() { UserID = Guid.NewGuid(), DOB = DateTime.Now, Name = "arun" });
            listUser.Add(new User() { UserID = Guid.NewGuid(), DOB = DateTime.Now, Name = "somu" });

            ////Bulk insert patient data
            connection.BulkInsert<User>(listUser);
            int i = 0;
            foreach (var item in listUser)
            {
                item.Name = item.Name + i.ToString();
                i++;
            }

            ///connection = new SQLiteAsyncConnection(string.Format("{0}\\{1}", Dbpath.Path, "Sqlitedb.db"));
            ////Bulk update patient data
            connection.BulkUpdate<User>(listUser);

            ////Bulk delete patient data
            connection.BulkDelete<User>(listUser);

        }

        #endregion

        private async void btnRead_Click(object sender, RoutedEventArgs e)
        {
            if (connection == null)
            {
                var Dbpath = await KnownFolders.DocumentsLibrary.CreateFolderAsync("DBFile", CreationCollisionOption.OpenIfExists);
                connection = new SQLiteAsyncConnection(string.Format("{0}\\{1}", Dbpath.Path, "Sqlitedb.db"));
            }

            //////Create table
            connection.CreateTableAsync<User>();

            var listUser = new List<User>();
            listUser.Add(new User() { UserID = Guid.NewGuid(), DOB = DateTime.Now, Name = "senthil" });
            listUser.Add(new User() { UserID = Guid.NewGuid(), DOB = DateTime.Now, Name = "arun" });
            listUser.Add(new User() { UserID = Guid.NewGuid(), DOB = DateTime.Now, Name = "somu" });

            ////Bulk insert patient data
            connection.BulkInsert<User>(listUser);

            List<User> users = connection.Table<User>().ToList();

            gridview1.ItemsSource = users;
        }

        private async void btn_Encrypt_Click(object sender, RoutedEventArgs e)
        {
            var Dbpath = await KnownFolders.DocumentsLibrary.CreateFolderAsync("DBFile", CreationCollisionOption.OpenIfExists);
            connection = new SQLiteAsyncConnection(string.Format("{0}\\{1}", Dbpath.Path, "Sqlitedb.db"));
            //// If the file already encrypted,Should be uncomment the below statement and provide password for reading file
            ////connection.DBPassword("abcd1234");

            //// need to provide password for encrypt db file
            connection.ChangePassword("abcd1234");

            ////Create table
            connection.CreateTableAsync<User>();


            ////Create table
            connection.CreateTableAsync<User>();

            var listUser = new List<User>();
            listUser.Add(new User() { UserID = Guid.NewGuid(), DOB = DateTime.Now, Name = "senthil" });
            listUser.Add(new User() { UserID = Guid.NewGuid(), DOB = DateTime.Now, Name = "arun" });
            listUser.Add(new User() { UserID = Guid.NewGuid(), DOB = DateTime.Now, Name = "somu" });

            connection.BulkInsert<User>(listUser);


        }

        private void btn_Shrink_Click(object sender, RoutedEventArgs e)
        {
            connection.DatabaseShrink();
        }

    }
}
