using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Microsoft.AspNetCore.Http;

namespace OOPHw.Models
{
    public class Movie
    {
        public int Id { get; set; }

        [Required(ErrorMessage = "Film adı zorunludur.")]
        [StringLength(100, ErrorMessage = "Film adı en fazla 100 karakter olabilir.")]
        [Display(Name = "Film Adı")]
        public string Title { get; set; } = string.Empty;

        [Required(ErrorMessage = "Film türü zorunludur.")]
        [StringLength(50, ErrorMessage = "Tür en fazla 50 karakter olabilir.")]
        [Display(Name = "Tür")]
        public string Genre { get; set; } = string.Empty;

        [Required(ErrorMessage = "Yönetmen alanı zorunludur.")]
        [StringLength(100, ErrorMessage = "Yönetmen adı en fazla 100 karakter olabilir.")]
        [Display(Name = "Yönetmen")]
        public string Director { get; set; } = string.Empty;

        [Required(ErrorMessage = "Yayın yılı zorunludur.")]
        [Range(1888, 2100, ErrorMessage = "Lütfen geçerli bir yayın yılı giriniz (1888 - 2100).")]
        [Display(Name = "Yayın Yılı")]
        public int ReleaseYear { get; set; }

        [Required(ErrorMessage = "Puan alanı zorunludur.")]
        [Range(0.0, 10.0, ErrorMessage = "Puan 0.0 ile 10.0 arasında olmalıdır.")]
        [Display(Name = "Puan (10 üzerinden)")]
        public double Rating { get; set; }

        [Display(Name = "Afiş Resmi")]
        public string? PosterPath { get; set; }

        [Display(Name = "Favori")]
        public bool IsFavorite { get; set; } = false;

        [NotMapped]
        [Display(Name = "Afiş Resmi Seçin")]
        public IFormFile? PosterFile { get; set; }
    }
}
