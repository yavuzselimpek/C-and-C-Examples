# Best Time to Buy and Sell Stock II

## Problem Tanımı

Bu problemde, verilen bir dizi hisse senedi fiyatı üzerinden en yüksek karı elde etmeyi amaçlıyoruz. Amaç, birden fazla kez alım satım yaparak maksimum karı elde etmek. Hisse senedi fiyatları her gün değiştiğinden, her alım ve satım arasındaki farkı kullanarak karınızı hesaplayabilirsiniz.

- **Girdi**: `prices = [7,1,5,3,6,4]`
- **Çıktı**: `maxProfit = 7`
- **Açıklama**: 2. günde (fiyat = 1) alım yapıp, 3. günde (fiyat = 5) satış yaparak 5-1 = 4 kar elde edilir.
Sonrasında 4. günde (fiyat = 3) alım yapıp, 5. günde (fiyat = 6) satış yaparak 6-3 = 3 kar elde edilir.
Bu durumda toplam kar 4 + 3 = 7 olur.

> Not: Birden fazla işlem yapabilirsiniz, ancak her işlemde yalnızca bir kez alım ve bir kez satış yapılabilir. Maksimum karı bulmanız gerekmektedir.

---

## Algoritmanın Mantığı

1. **Başlangıç Değeri**: İlk fiyatı `start = prices[0]` olarak alıyoruz.
2. **Dizi Üzerinde Gezinme**: Dizi üzerinde ikinci elemandan itibaren döngüye giriyoruz.
3. **Kar Hesaplama**: Eğer şu anki fiyat bir önceki fiyattan büyükse, bu durumda kar elde etmiş oluyoruz ve bu farkı `max` değişkenine ekliyoruz.
4. **Başlangıç Fiyatını Güncelleme**: Satış yaptıktan sonra, yeni alım fiyatını güncelliyoruz ve bu işlemle birlikte `start` fiyatını bir sonraki günün fiyatı ile güncelliyoruz.
5. **Sonuç**: En son elde ettiğimiz `max`, toplam maksimum karımızı verir.

---

## C Kodu Açıklama

```c
int maxProfit(int* prices, int pricesSize) {
    int max = 0; // Maksimum karı tutacak değişken
    int start = prices[0]; // İlk fiyatı başlangıç olarak kabul ediyoruz
    for(int i = 1; i < pricesSize; i++) { // Dizi üzerinde gezinmeye başlıyoruz
        if(start < prices[i]) { // Eğer şu anki fiyat önceki fiyatın üstündeyse
            max += prices[i] - start; // Karı ekliyoruz
        }
        start = prices[i]; // Yeni alım fiyatını güncelliyoruz
    }
    return max; // Sonuç olarak maksimum karı döndürüyoruz
}

```

# C++ ile C Kodu Arasındaki Farklar
C ve C++ arasındaki bazı temel farkları belirlemek gerekirse:

1. **Veri Yapıları ve Nesne Yönelimli Programlama (OOP)**

- **C:** C dilinde, fonksiyonel programlama yaklaşımı kullanılır ve genellikle veriler yapılandırılmamış biçimde işlenir. Nesne yönelimli programlama (OOP) desteği yoktur.
- **C++:** C++ dilinde, nesne yönelimli programlama (OOP) desteklenir. Sınıflar (classes) ve nesneler (objects) gibi kavramlar sayesinde daha modüler ve sürdürülebilir kod yazılabilir.

2. **Bellek Yönetimi ve Akışlar**

- **C:** C dilinde bellek yönetimi manuel olarak yapılır. malloc(), calloc(), free() gibi fonksiyonlar kullanılır.
- **C++:** C++ dilinde, otomatik bellek yönetimi sağlar ve new, delete gibi operatörler kullanılır. Ayrıca, C++'ın daha zengin veri türleri ve kütüphaneleri vardır, örneğin std::vector gibi dinamik diziler kullanabilirsiniz.

 - ``C++'ta vektör kullanımı:``

 ```c 
 std::vector<int> prices = {7, 1, 5, 3, 6, 4};
int result = maxProfit(prices, prices.size());
 ```

 3. **Standart Kütüphane Kullanımı**

 - **C:** C dilinde, standart kütüphane fonksiyonları ve veri yapıları sınırlıdır. Veri yapıları genellikle diziler ve işlevsel fonksiyonlarla sınırlıdır.
- **C++:** C++ dilinde, STL (Standard Template Library) gibi geniş bir kütüphane desteği vardır. ``std::vector``, ``std::string``, ``std::map`` gibi veri yapıları, C++'ın daha esnek ve kullanışlı hale gelmesini sağlar.

4. **Error Handling (Hata Yönetimi)**

- **C:** C dilinde hata yönetimi daha az yapısaldır. Çoğunlukla dönüş değerleri ile hata durumları kontrol edilir.
- **C++:** C++ dilinde daha gelişmiş hata yönetimi bulunur. try, catch, ve throw ifadeleri ile istisnalar (exceptions) kontrol edilebilir.

5. **Fonksiyonel Programlama ve Lambda İfadeleri**
- **C:**  C dilinde fonksiyonel programlama desteği sınırlıdır. Fonksiyonlar, veri işleme için genellikle dışarıdan çağrılır.
- **C++:** C++ dilinde, lambda fonksiyonları gibi fonksiyonel programlama özellikleri bulunur.

``C++ Lambda Fonksiyonu Örneği:``

 ```c 
std::for_each(prices.begin(), prices.end(), [](int price) {
    std::cout << "Price: " << price << std::endl;
});
 ```
 > Bu kod, std::for_each fonksiyonu ve bir lambda fonksiyonu kullanarak, prices vektöründeki tüm elemanları yazdırmayı amaçlıyor. Şimdi her bir parçayı detaylıca inceleyelim.

 ## `std::for_each` ve Lambda Fonksiyonu ile Koleksiyon Üzerinde İşlem Yapma

## 1. `std::for_each(prices.begin(), prices.end(), ...)`

`std::for_each`, algoritmalar kütüphanesine ait bir fonksiyondur. Bu fonksiyon, bir koleksiyondaki (bu örnekte `prices` adlı bir vektör) her öğe üzerinde bir işlem yapmak için kullanılır.

- `prices.begin()`: Bu, `prices` vektörünün ilk elemanının adresini döndüren bir iteratördür. Yani, iterasyon başlatmak için kullanılır.
- `prices.end()`: Bu, `prices` vektörünün sonrasındaki ilk elemanın adresini döndüren bir iteratördür. Yani, bu iteratör sonu belirtir ve iterasyon burada biter.

`std::for_each`, verilen koleksiyondaki her bir eleman üzerinde belirtilen fonksiyonu çalıştırır. Bu fonksiyona, `prices` vektöründeki her bir eleman sırayla tek tek geçilir.

## 2. `[](int price) { ... }` - Lambda Fonksiyonu

Bu kısım, lambda fonksiyonunun tanımıdır.

- `[]`: Lambda'nın **capture list**idir. Yani, dışarıdaki değişkenlere nasıl erişileceğini belirler. Burada boş bırakıldığı için lambda, dışarıdaki hiçbir değişkene erişmiyor. Yani, sadece kendi parametresine ve kendi içindeki koduna odaklanacak.

  Eğer burada dışarıdaki değişkenlere erişmek istenseydi, örneğin tüm dış değişkenleri kopyalamak için `[=]`, sadece referans olarak almak için `[&]` yazılabilirdi.

- `(int price)`: Lambda'nın parametre listesidir. Burada, her bir öğe (veya her bir fiyat) `int price` olarak lambda fonksiyonuna parametre olarak geçer.
- `price`: Bu, her bir vektör elemanını temsil eder. `std::for_each` fonksiyonu, `prices` vektöründeki her bir elemanı `price` parametresine gönderir.
- `{ std::cout << "Price: " << price << std::endl; }`: Lambda'nın gövdesidir, yani yapılacak işlemi belirler. Bu işlem, her bir öğe için `std::cout` kullanarak öğeyi yazdırmaktır.

## 3. Kodun İşleyişi

Örneğin, `prices` adında şu şekilde bir vektör olduğunu varsayalım:

```cpp
std::vector<int> prices = {100, 200, 300, 400, 500};
```
Şimdi kodu çalıştırdığınızda, ``std::for_each`` fonksiyonu ``prices`` vektöründeki her bir öğe için lambda fonksiyonunu çağırır. Her bir öğe ``price`` parametresine aktarılır ve lambda fonksiyonu bu öğeyi ekrana yazdırır.

## 3. Çıktı

Yukarıdaki örnek vektörle çalıştığınızda, ekrana şu şekilde bir çıktı basılır:

```cpp
Price: 100
Price: 200
Price: 300
Price: 400
Price: 500
```


---
 # Sonuç

 C ve C++ arasındaki farklar, dilin paradigmasına ve kullanım amacına göre belirginleşir. C, daha düşük seviyeli ve sistem programlaması için tercih edilirken, C++ daha gelişmiş yazılım uygulamaları için nesne yönelimli özellikler ve geniş kütüphaneler sağlar. Bu nedenle, projenizde daha modüler ve sürdürülebilir bir yapıya ihtiyaç duyarsanız, C++ tercih edilebilir. Ancak, C dilindeki basitlik ve düşük seviyeli kontrol avantajları da göz önünde bulundurulmalıdır.