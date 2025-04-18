# C Diline Uygun `merge()` Fonksiyonu Detaylı Açıklama

Bu belge, C programlama dili ile yazılmış `merge()` fonksiyonunun ne yaptığını, nasıl çalıştığını ve hangi durumlarda kullanılabileceğini kapsamlı şekilde açıklar. Fonksiyon, sıralı iki diziyi (nums1 ve nums2) birleştirerek tek bir sıralı dizi haline getirir. Bu tür işlemler, LeetCode gibi algoritma platformlarında sıklıkla karşılaşılan klasik bir problem olan "Merge Sorted Array" sorusunda kullanılmaktadır.

---

## 📌 Fonksiyon Tanımı

```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
```

### Parametreler

| Parametre     | Açıklama                                                                 |
|---------------|--------------------------------------------------------------------------|
| `nums1`       | İlk sıralı dizi. İçerisine `nums2`'nin elemanları da eklenecektir.       |
| `nums1Size`   | `nums1` dizisinin toplam kapasitesi (m + n).                             |
| `m`           | `nums1` dizisinde başlangıçta bulunan geçerli (sıralı) eleman sayısı.     |
| `nums2`       | İkinci sıralı dizi. Bu dizinin tüm elemanları `nums1` dizisine eklenecek.|
| `nums2Size`   | `nums2` dizisinin kapasitesi (n).                                        |
| `n`           | `nums2` dizisinde bulunan geçerli (sıralı) eleman sayısı.                |

---

## ⚙️ Fonksiyonun Çalışma Mantığı

Fonksiyon, sıralı olan iki tamsayı dizisini (`nums1` ve `nums2`) birleştirip `nums1` içinde sıralı şekilde saklar. 

### Neden sondan başlanır?
`nums1` dizisinin sonunda, `nums2` elemanlarının sığacağı kadar boş alan vardır. Eğer baştan başlanırsa, mevcut elemanların üzerine yazmak gerekebilir. Bu nedenle dizilerin en son elemanlarından başlanarak karşılaştırma yapılır ve büyük olan eleman `nums1`'in sonuna yerleştirilir.

### Adım Adım İşleyiş

1. `index1` → `nums1` dizisinin son geçerli elemanını (m-1)
2. `index2` → `nums2` dizisinin son elemanını (n-1)
3. `mergeIndex` → birleşmiş dizinin son indexi (m+n-1)

```c
int index1 = m - 1;
int index2 = n - 1;
int mergeIndex = m + n - 1;
```

4. `nums2` boşalana kadar (index2 >= 0) döngü devam eder.
5. `nums1[index1] > nums2[index2]` kontrolü yapılır.
   - Eğer doğruysa, `nums1[mergeIndex] = nums1[index1]` yapılır.
   - Değilse, `nums1[mergeIndex] = nums2[index2]` yapılır.
6. Her adımda uygun index 1 azaltılır.

```c
while (index2 >= 0) {
    if (index1 >= 0 && nums1[index1] > nums2[index2]) {
        nums1[mergeIndex--] = nums1[index1--];
    } else {
        nums1[mergeIndex--] = nums2[index2--];
    }
}
```

---

## 💡 Örnek Kullanım

```c
int nums1[6] = {1, 3, 5, 0, 0, 0};
int nums2[3] = {2, 4, 6};
merge(nums1, 6, 3, nums2, 3, 3);
```

İşlemden sonra `nums1`: 
```c
{1, 2, 3, 4, 5, 6}
```

---

## 🧠 Notlar
- Bu fonksiyon *in-place* olarak çalışır, yani ekstra belleğe ihtiyaç duymaz.
- `nums1` dizisinin sonu yeterli büyüklükte olmalıdır (en az `m+n`).

---

## 🔚 Sonuç
C diline uygun bu `merge()` fonksiyonu, iki sıralı diziyi etkili bir biçimde tek bir sıralı diziye dönüştürür. Hafıza açısından verimli ve algoritmik olarak güçlü bir çözümdür. Gerçek dünya uygulamaları ve algoritma soruları için ideal bir örnektir.

---

## 📚 C ve C++ Arasındaki Farklar – merge() Fonksiyonu Bağlamında

---

C ve C++ dillerinde aynı algoritma benzer mantıkla yazılsa da, dil özellikleri nedeniyle farklılıklar gösterir:

1.   ***Veri Yapıları***

C: Düz dizi (array) yapıları ve malloc gibi C kütüphaneleri kullanılır.

C++: vector<int> gibi STL (Standard Template Library) yapıları tercih edilir.

2. ***Bellek Yönetimi***

C: Bellek elle yönetilir (malloc/free).

C++: Otomatik yönetim, new/delete, RAII gibi kavramlar vardır.

3. ***Fonksiyon Tanımı***

C: Fonksiyonlar sade, prosedürel yazılır.

C++: Fonksiyonlar genellikle sınıflar içinde tanımlanabilir ve nesne tabanlıdır.

4. ***Yazım Kolaylığı***

C: Daha detaylı bellek işlemleri gerekir.

C++: std::merge() gibi hazır fonksiyonlar mevcuttur. Kendi merge() fonksiyonunu yazmak yerine bu fonksiyonlar tercih edilebilir.

5. ***Kod Örneği İle Karşılaştırma***

C Örneği: Düz dizi içerisinde çalışma, dizilerin sondan birleştirilmesi.

C++ Örneği: vector kullanılır, bazen insert(), sort() gibi fonksiyonlarla tek satırda işlem yapılabilir.

Bu farklar, dil tercihi ve uygulama ihtiyacına göre değiştir. Ancak mantık aynı kalmakla birlikte C++ geliştiriciye daha fazla kolaylık ve okunabilirlik sağlar.

