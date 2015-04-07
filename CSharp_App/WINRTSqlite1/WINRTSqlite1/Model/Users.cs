using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace sqllite.Model
{
    public class User
    {
        [System.ComponentModel.DataAnnotations.Key]
        public Guid UserID { get; set; }

        public string Name { get; set; }

        public DateTime DOB { get; set; }

        public byte[] Image { get; set; }
    }
}
