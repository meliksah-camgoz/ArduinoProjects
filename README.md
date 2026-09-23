# 🔧 Arduino Projects

Bu repository, üniversite eğitimim sırasında **Arduino ve temel elektronik sistemler** üzerine geliştirdiğim çeşitli uygulama ve projeleri içermektedir.

Projeler, ders ve kişisel çalışma süreçlerinde Arduino'nun sensörler, motorlar, LED'ler, buzzer ve çeşitli elektronik bileşenlerle birlikte kullanımını öğrenmek ve pratik yapmak amacıyla geliştirilmiştir.

---

## 📌 Proje İçeriği

Repository içerisinde farklı amaçlara yönelik çeşitli Arduino projeleri bulunmaktadır.

### 🔥 Alev Algılama Sistemi

`alev.ino`

Alev sensörü kullanılarak ortamda oluşabilecek alevin algılanmasını sağlayan basit bir Arduino uygulamasıdır.

Sensörden alınan veriye göre sistemin tepki vermesi ve kullanıcıya uyarı verilmesi üzerine geliştirilmiştir.

**Kullanılan teknolojiler:**
- Arduino
- Alev sensörü
- LED
- Buzzer

---

### 🔊 Buzzer Uygulaması

`buzzer.ino`

Arduino üzerinde buzzer kullanımı, ses üretimi ve farklı elektronik bileşenlerle etkileşim üzerine hazırlanmış temel bir uygulamadır.

Arduino'nun dijital çıkışlarının kullanılması ve belirli koşullarda sesli uyarı oluşturulması amaçlanmıştır.

---

### 🌍 Deprem Uyarı Sistemi

`deprem.ino`

Deprem veya titreşim algılama mantığını deneyimlemek amacıyla hazırlanmış bir Arduino projesidir.

Sensörlerden alınan titreşim verileri değerlendirilerek belirli bir eşik değerinin üzerinde uyarı oluşturulması üzerine geliştirilmiştir.

**Proje kapsamında:**
- Sensör verisi okuma
- Eşik değer kontrolü
- LED/buzzer ile uyarı
- Arduino dijital giriş/çıkışları

gibi temel konular üzerinde çalışılmıştır.

> Bu proje eğitim ve prototipleme amacıyla hazırlanmıştır; gerçek bir deprem erken uyarı sistemi olarak kullanılmamalıdır.

---

### 💡 Düğmeli Lamba Sistemi

`dugmelilamba_oct25a.ino`

Push-button ve LED kullanılarak hazırlanmış temel bir aydınlatma kontrol uygulamasıdır.

Butona basılmasıyla LED'in açılıp kapatılması ve Arduino üzerinden dijital girişlerin kontrol edilmesi üzerine geliştirilmiştir.

**Kullanılan bileşenler:**
- Arduino
- Push Button
- LED
- Direnç

---

### 🏠 Akıllı Ev Sistemi

`projeEvSistemi.ino`

Arduino kullanılarak temel bir **akıllı ev otomasyonu** mantığını deneyimlemek amacıyla geliştirilmiş projedir.

Sistem içerisinde çeşitli giriş ve çıkış bileşenleri kullanılarak ev içerisindeki bazı cihazların Arduino üzerinden kontrol edilmesi amaçlanmıştır.

Bu proje ile;

- Sensörlerden veri alma
- Dijital giriş/çıkış kullanımı
- Otomasyon mantığı
- Elektronik bileşenlerin Arduino ile kontrolü

konularında çalışma yapılmıştır.

---

## 🛠️ Kullanılan Teknolojiler

- **Arduino**
- **C / Arduino C++**
- Sensörler
- LED
- Buzzer
- Push Button
- Temel elektronik devre elemanları

---

## 🎯 Projenin Amacı

Bu repository'nin temel amacı, eğitim sürecinde Arduino platformunu kullanarak **programlama ile elektronik sistemlerin birlikte nasıl çalıştığını öğrenmek** ve farklı donanım bileşenleriyle uygulama geliştirme deneyimi kazanmaktır.

Projeler sayesinde;

- Arduino programlama,
- Sensörlerden veri okuma,
- Dijital giriş ve çıkışlar,
- Elektronik devrelerin kurulması,
- Donanım-yazılım etkileşimi,
- Basit otomasyon sistemleri

gibi konularda pratik yapılmıştır.

---

## 📂 Dosya Yapısı

```text
ArduinoProjects
│
├── alev.ino
├── buzzer.ino
├── deprem.ino
├── dugmelilamba_oct25a.ino
├── projeEvSistemi.ino
│
└── README.md
