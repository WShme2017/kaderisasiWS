# Tugas Kelompok 1

## Kalkulator : ***WSCalc 2017***

### A. Pemberian tugas : 05 September 2017

### B. Cara Kerja Kalkulator WSCalc 2017 (Spesifikasi Tugas, mandatory)
  1.	**Saat pertama dinyalakan, LCD kalkulator akan menampilkan running text** bertuliskan “WSCalc 2017 Calculator” pada baris pertama, dan "Made by Kelompok ?" pada baris kedua
  2.	**Memulai komputasi** dengan menekan *keypad enter* saat keypad ditekan akan masuk ke kondisi menginput operand A
  3.	**Masukan bilangan A** (dengan menekan *keypad angka*) </br  >
  4.	**Submit bilangan A** dengan menekan *keypad enter* saat *keypad enter* ditekan, maka kondisi berganti ke operator
  5.	**Masukan operator** (dengan menekan *button A* untuk mengganti operator) </br  >
  6.  **Submit operator** (dengan menekan *keypad enter* saat *keypad enter* ditekan, maka kondisi berganti ke operand B
  7.	**Masukan bilangan B** (dengan menekan *keypad angka*) </br  >
  8.	**Submit bilangan B** dengan menekan *keypad enter* saat *keypad enter* ditekan, maka kondisi berganti ke menampilkan hasil di LCD
  9.	**Ketika memasukkan bilangan A atau B, tulisan di LCD akan terupdate (sesuai nilai dari bilangan A dan B saat itu) tiap kali tombol input ditekan.** <br>
  10. **LCD menampilkan hasil kalkulasi** :heart_eyes:
  11. Tekan *keypad enter* , **kalkulator kembali ke keadaan semula**

### C. Detail Tugas
  1.  Membuat desain PCB ***WSCalc 2017***
  2.	Membuat kode Arduino kalkulator ***WSCalc 2017***
  3.	Membuat rangkaian kalkulator ***WSCalc 2017*** (Cetaklah PCB `tertata baik` dan `memorable`)
  4.  Menambahkan satu fitur tambahan
  5.	Membuat dan mengupload file dokumentasi dan laporan ke folder yang sesuai di repository kaderisasiWS (caranya dapat dilihat pada file README.md pada root directory repository)
  6.	File yang harus di upload :
      <br> > Source code WSCalcKelompok?.ino
      <br> > PCB design file (semua file dimasukkan ke PCBKelompok?.zip)
      <br> > Image produk jadi (Kelompok?.png atau Kelompok?.jpg)
      <br> > Dokumentasi tugas (TK1Kelompok?.docx) **(template terlampir)**

### D. Fitur Premium Kalkulator WSCalc 2017 (Spesifikasi Bonus, supplementory)
  * **Dapat di delete** operand yang di input
  * **Buat board rangkaian sedemikian rupa sehingga rangkaian dapat dijadikan shield Arduino.** (*Shields are boards that can be plugged on top of the Arduino PCB extending its capabilities.* -https://www.arduino.cc/en/Main/ArduinoShields)

### E. Rangkaian Kalkulator WSCalc 2017
  * **Rangkaian push button** gunakan internal pull up atau pull down dari Arduino</br  >
  ![push](https://github.com/WorkshopHMEITB/KaderisasiWS2016/blob/master/assets/images/push.PNG)
  * **Rangakain LED** </br  >
  ![LED](https://github.com/WorkshopHMEITB/KaderisasiWS2016/blob/master/assets/images/LED.PNG)
  * **Salah satu kemungkinan rangkaian untuk menghubungkan LCD dengan Arduino** (Jangan lupa untuk menyesuaikan parameter pada insialisasi LCD sebelum *setup loop*. Jika ingin menggunakan rangkaian yang dibawah ini dengan persis, maka tuliskan *LiquidCrystal lcd(12, 13, 5, 4, 3, 2);* sebelum *setup loop*)</br  ></br  >
![lcdarduino](https://github.com/wshme2017/kaderisasiWS/blob/master/assets/images/lcdarduino.jpg)

### F. Informasi Tambahan
  * Rangkaian harus dicetak PCB dilarang double side (setiap kelompok hanya 1 PCB)
  * Dilarang menggunakan kabel jumper pada tugas ini (arduino dengan PCB dihubungkan dengan male header)
  * Untuk keperluan tugas ini cakru dipersilahkan konsultasi kepada mentor masing-masing
  * Wajib menggunakan keypad
  
### G. Deadline
  * 25-29 September 2017 (Deadline Presentasi ke mentor)
  * 29 September 2017 (Upload ke github)
  * Keterlambatan akan mengakibatkan konsekuensi minus (%) terhadap nilai
  
### H. Fitur Tambahan
#### Pilih minimal salah satu dari fitur di bawah ini (diperbolehkan menambah fitur lain) :
  * Trigonometric function (sin, cos, and tan)
  * Squareroot and power
  * Convert decimal to binary and hexadecimal
  * Prime number
  * Palindrom
  * Logarithm and natural logarithm
  
<br> <br>
CP : William Chandra (LINE : william_chans)
<br> <br> <br>
##### #WorkshopJayadanKaya
