# Engine / Sandbox mimarisi — Day 2

Bağımlılık yönü: `Sandbox -> CanEngine`. Engine, Sandbox kodunu veya
başlıklarını kullanmaz. Kök CMake dosyası iki hedefi bir araya getirir.

## Dosyaların sorumlulukları

| Konum | Sorumluluk |
| --- | --- |
| `engine/include/CanEngine/Engine.h` | Motorun dışarı açtığı arayüz: `CanEngine::Engine` ve `Run()` bildirimi. |
| `engine/src/Engine.cpp` | Arayüzün uygulaması; şimdilik başlatma mesajını yazdırır. |
| `engine/CMakeLists.txt` | `CanEngine` static library hedefi, dışa açık include yolu ve C++20 gereksinimi. |
| `sandbox/src/main.cpp` | Uygulamanın giriş noktası; motoru oluşturur ve çalıştırır. |
| `sandbox/CMakeLists.txt` | `Sandbox` executable hedefi ve CanEngine bağlantısı. |
| `assets/` | Demo içerikleri; ileride doku ve shader gibi dosyalar. |
| `tests/` | İleride otomatik doğrulamalar; Sandbox demo uygulamasından ayrı. |

Header (`.h`) başka dosyaların neyi kullanabileceğini bildirir; source (`.cpp`)
bu davranışın nasıl gerçekleştiğini tanımlar. Sandbox yalnızca
`<CanEngine/Engine.h>` ekler; `Engine.cpp` eklemez ve engine'in iç dosyalarına
göreli yollarla erişmez.

CanEngine tek başına çalışan bir program değildir. Derlendiğinde static library
oluşur; gereken motor kodu bağlantı aşamasında `Sandbox.exe` içine alınır.
Sandbox kendi `main()` fonksiyonuna sahip çalıştırılabilir uygulamadır.

## Yeni kod nereye konmalı?

- **Engine:** farklı uygulamalarda tekrar kullanılabilecek pencere, giriş,
  zamanlama, loglama ve çizim sistemleri; bunların genel arayüzleri.
- **Sandbox:** demo sahnesi, belirli nesneler, seçilen dokular, oyun kuralları,
  örnek kamera kontrolü ve motora verilen uygulamaya özel ayarlar.
- Örneğin klavyeyi sorgulama API'si engine'e; W tuşuyla demo kamerasını hareket
  ettirme kararı Sandbox'a aittir. Doku yükleme sistemi engine'e; hangi dokunun
  hangi demo nesnesine atanacağı Sandbox'a aittir.

`PUBLIC` include yolu ve C++20 gereksinimi, CanEngine'e bağlanan Sandbox'a
CMake tarafından aktarılır. `PRIVATE` link, Sandbox'ın bu kütüphaneyi kendi
uygulaması için kullandığını belirtir. Genel include/link ayarları gerekmez.

## Derleme ve çalıştırma (PowerShell)

Gerekli araçlar: CMake, PATH üzerinde UCRT64 `g++` ve `mingw32-make`.
Proje kökünde:

```powershell
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
.\build\sandbox\Sandbox.exe
```

Beklenen çıktı: `CanEngine initialized.`

Day 2 mevcut mimari sınırlarını netleştirir. `Engine::Run()` henüz bir oyun
döngüsü değildir. Application sınıfı Day 3, oyun döngüsü Day 4 kapsamındadır.
