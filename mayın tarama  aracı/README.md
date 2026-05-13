🛡️ Mayın Tarama Aracı (Arduino)
Bu proje, LJ12A3-4-Z/BX Endüktif Mesafe Sensörü kullanarak yer altındaki veya yüzeydeki metalleri (mayın simülasyonu) tespit eden, LCD ekran üzerinden kullanıcıyı bilgilendiren ve tehlike anında durup alarm veren bir robot projesidir.
🛠️ Kullanılan Bileşenler
Arduino Uno
I2C LCD Ekran (16x2)
L298N Motor Sürücü
LJ12A3-4-Z/BX Endüktif Mesafe Sensörü
Buzzer ve DC Motorlar
📦 Gerekli Kütüphaneler
Bu kodun çalışması için LiquidCrystal_I2C kütüphanesinin Arduino IDE'sine yüklü olması gerekir.
Kodun İçinde Küçük Bir Düzeltme
Kodunda lcd.begin(); fonksiyonu bazı yeni kütüphane versiyonlarında hata verebilir veya LCD ekranın çalışmamasına sebep olabilir. Eğer ekranın çalışmazsa o satırı şununla değiştirmeyi dene:
lcd.init();
