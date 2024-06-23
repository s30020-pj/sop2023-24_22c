# Instalacja debiana na maszynie wirtualnej virtualbox

## Wymagane:

1.  Komputer

2.  Obraz debiana

3.  Zainstalowany virtualbox

## Proces tworzenia maszyny:

1.  Uruchomić program virtualbox -- w tym przypadku zrobimy to w wersji
    graficznej

2.  Z górnej części okna wybrać „Nowa" -- tworzymy nową maszynę

3.  Pojawia się okno konfiguracji wstępnej, na starcie warto od razu
    wejść w tryb eksperta dostępny na dole okna

4.  Wstępnie skonfigurować maszynę:

    a.  Pierwszy krok: Nazwa maszyny i System operacyjny

        i.  Nazwa może być dowolna, warto zauważyć, że podanie w nazwie
            maszyny nazwę systemu, przykładowo podajemy „Debian", niżej
            widać, że virtualbox sam doszedł do wniosku, że będziemy
            instalować dystrybucję Linuxa o nazwie „Debian".

        ii. Folder: Należy wybrać katalog w którym umieścimy wirtualną
            maszynę. Ważne jest, aby zrobić to na nośniku danych który
            ma dostępną przestrzeń.

        iii. W tym przypadku zaznaczamy „Skip unattended installation",
             aby zainstalować system ręcznie. Inaczej virtualbox
             zapytałby się o pewne informacje pre-konfiguracyjne aby
             zainstalować system z najmniejszym udziałem użytkownika w
             tym procesie.

    b.  Drugi krok: Hardware

        i.  Trzeba ustalić parametry maszyny, w tym celu można
            skorzystać z dokumentacji debiana, a konkretniej z
            wyznaczonych w niej minimalnych/zalecanych parametrach.
            Warto ustawić zalecane parametry, gdyż to one zagwarantują
            płynne działanie systemu operacyjnego (W tym przypadku 2GB
            RAM oraz 10GB przestrzeni dyskowej, przestrzeń dyskowa
            będzie później). Liczba rdzeni przypisanych do maszyny
            powinna być uzależniona od potrzeb. W celu tylko postawienia
            czystego systemu wybiorę 2GB ramu oraz 2 rdzenie aby
            instalacja przeszła płynnie. Warto pamiętać żeby wybierać
            wartości, które są krotnością dwójki.

        ii. Enable EFI -- Warto zaznaczyć ale też wypada wiedzieć, czy
            wybrany system wspiera EFI (Debian wspiera). EFI jest o
            wiele wydajniejszym łącznikiem Software -- Hardware niż BIOS
            i zapewnia większą elastyczność systemowi.

    c.  Trzeci krok: Hard Disk

        i.  Wybieramy ścieżkę, w której będzie znajdować się wirtualny
            dysk -- wybierz nośnik, który ma dostępną przestrzeń.

        ii. Dostępne są poniższe formaty wirtualnych dysków:
            1. VDI - Natywny format dysku w virtualboxie,
            oferuje nalepszą kompatybilność. Wspiera dynamiczną
            alokację danych.

            2. VMDK - Format wspierający dynamiczną alokację danych,
            natywny format dla VMWare. Wyróżnia się wysoką kompatybilnością
            z wieloma środowiskami wirtualizacyjnymi (VMWare,
            VirtualBox, QEMU). Posiada zdolność do przechowywania
            jednego pliku jako pliki mniejsze niż 2GB. Przydatne,
            Jeśli korzystamy z systemu plików z niskim limitem rozmiaru
            pliku.

            3. VHD - Natywny format Microsoft Virtual PC. Wspiera
            dynamiczną alokację przestrzeni.

            4. HDD - Format plików z kompatybilnością dla Parallels 
            (wirtualizacja dla macOS). VirtualBox wspiera jedynie
            starą wersję tego formatu

            5. QCOW - Stary format QUEMU, wyparty przez QCOW2

            6. QED - Porzucony format będący ulepszeniem dla QCOW
        
            Wg. zalecanych parametrów powinniśmy ustawić przynajmniej
            10GB przestrzeni dyskowej, tak więc można ustawić 10GB albo
            jak ja -- ustawić 20GB (później opiszę dlaczego).

        iii. Pre-allocate Full Size -- opcja pozwalająca na zaalokowanie
             pełnej przestrzeni dyskowej przez nas wybranej -- domyślnie
             dysk witrualny powiększa się dynamicznie -- jak jest taka
             potrzeba. Zaznaczenie tej opcji powinno nieco zwiększyć
             wydajność, ponieważ komputer nie musi regularnie powiększać
             dysku wirtualnego. Akurat w tym przypadku nie potrzebujemy 
             aż tak wysokiej efektywności w działaniu pamięci, więc 
             nie zaznaczam tej opcji aby zaoszczędzić miejsce na maszynie 
             hostującej. Zauważmy, że można wybrać jeszcze dysk wirtualny, 
             który już istnieje lub w ogóle nie dodawać dysku.

        iv. Kończymy wstępną konfigurację przyciskiem „Zakończ"

    d.  Przechodzimy do ustawień maszyny (Przycisk Ustawienia w głównym
        oknie virtualboxa):

        i.  Ogólne:

            1.  Podstawowe:

                a.  Nazwa Maszyny i system operacyjny -- można zmienić
                    jeśli jest taka potrzeba

            2.  Zaawansowane:

                a.  Folder migawek -- można tworzyć migawki systemu w
                    razie gdyby trzeba było wrócić do poprzedniego stanu
                    systemu, tutaj mamy opcję wyboru, gdzie te migawki
                    będą przechowywane,

                b.  Współdzielony schowek -- możliwość współdzielenia
                    schowka systemu hosta oraz systemu maszyny
                    wirtualnej, przydatne jeśli korzystamy z desktop
                    enviroment na maszynie,

                c.  Przeciąganie i Upuszczanie -- Łatwe przenoszenie
                    plików pomiędzy środowiskami graficznymi systemu
                    hosta oraz maszyny -- oczywiście również wymaga
                    desktop enviroment

            3.  Opis -- Miejsce na opis maszyny (np. żeby poinformować
                innych administratorów za co ta maszyna odpowiada)

            4.  Szyfrowanie dysku -- możliwość włączenia szyfrowania
                dysku wirtualnego -- spowoduje spowolnienie odczytu i
                zapisu ale zwiększy bezpieczeństwo danych.

        ii. System:

            1.  Płyta główna:

                a.  Możliwość zmiany ilości przydzielonego na maszynę
                    RAMu,

                b.  Zmiana kolejności bootowania z nośników

                c.  Chipset:

                    i.  PIIX3 -- Lepsza kompatybilność z virtualbox ale
                        mogą wystąpić problemy z kompatybilnością w
                        systemach Mac OS,

                    ii. ICH9 -- Bardziej zaawansowany chipset,
                        wspierający PCI express, trzy szyny PCI oraz
                        inne ulepszenia -- dla bardziej wymagających
                        użytkowników, eksperymentalny

                d.  TPM -- Trusted Platform Module -- moduł
                    kryptograficzny, może się przydać przy instalacji
                    maszyny z Windowsem 11

                e.  Urządzenie wskazujące -- w zależności od systemu
                    będziemy chcieli wybrać coś innego (kwestia
                    sterowników), przeważnie najlepszym wyborem jest
                    Mysz PS/2. Wybór bez znaczenia w przypadku
                    instalacji debiana o ile nie zamierzemy korzystać z
                    środowiska graficznego

                f.  Włącz I/O APIC -- Zaawansowany Kontroler przerwań --
                    służy softwareowi do wysyłania sygnału przerwania do
                    procesora.

                g.  Enable Hardware Clock in UTC Time -- urządzenie RTC
                    zgłosi systemowi czas w strefie UTC, Unixowe systemy
                    zazwyczaj oczekują, że zegar sprzętowy powinien być
                    ustawiony na UTC.

                h.  Enable Secure Boot -- Włączenie bezpiecznego
                    rozruchu opartego na kluczach

            2.  Procesory:

                a.  Możliwość zmiany przydzielonej liczby rdzeni

                b.  Wykorzystanie procesora - określa jak maksymalnie
                    proces mocy fizycznego procesora może być zajęty
                    przez daną maszynę. Ustawienie poniżej 50% może
                    powodować problemy.

                c.  Włącz PAE/NX -- Określa, czy możliwości PAE i NX
                    procesora hosta będą widoczne dla maszyny wirtualnej
                    -- w skrócie, może pozwolić na przydzielenie
                    większej ilości ramu niż 4GB systemom 32-bitowym.

                d.  Włącz zagnieżdżone VT-x/AMD-V -- Włączenie
                    wirtualizacji na niższym poziomie, domyślnie na
                    systemach windows systemy są witrualizowane na
                    Windowsie. Ta opcja pozwala zejść poziom niżej
                    dzięki czemu można uzyskać lepszą wydajność.

            3.  Akceleracja:

                a.  Interfejs parawirtualizacji -- parawirtualizacja to
                    technika wirtualizacji, w której wirtualizowany
                    system operacyjny współpracuje ze środowiskiem
                    operacyjnym komputera w zakresie obsługi tych
                    elementów sprzętowych, których obsługa kolidowałaby
                    z działalnością innych środowisk wirtualizowanych.
                    Do wyboru są różne interfejsy które różnie
                    współpracują z różnymi systemami.

                b.  Zagnieżdżone stronicowanie -- warto włączyć dla
                    nowszych procesorów (po \~2010)

        iii. Ekran:

             1.  Ekran:

                 a.  Pamięć wideo -- Aby uzyskać wymaganą ilość pamięci
                     wideo, pomnóż liczbę widocznych pikseli w linii
                     razy ilość linii, następnie wynik pomnóż razy
                     głębie kolorów. Dla ekranów o rozdzielczości
                     1024x768 z 32 bitową głębią kolorów będzie to 1024
                     \* 768 = 786432 pikseli, 786432 \* 32 = 25 165 824
                     bitów.\
                     25 165 824 / 8 = 3 145 728 bajtów co daje 3
                     Mebibajty (nieco ponad 3 Megabajty). Jednakże nie
                     są to wszystkie obliczenia jakie są tutaj
                     konieczne, ponieważ w grę wchodzi jeszcze ilość
                     wirtualnych monitorów, rozdzielczość ekranu i
                     głębia kolorów ekranu hosta. Zalecany wzór przez
                     twórców virtualboxa to (głębia kolorów / 8) x ilość
                     pikseli w pionie x ilość pikseli w poziomie x ilość
                     ekranów = ilość bajtów. W dokumentacji jest również
                     wzmianka o tym, że może być wymagana dodatkowa
                     pamięci jeśli jest używana akceleracja ekranu. Na
                     szczęście virtualbox nie jest głupim narzędziem i w
                     prosty sposób pokazuje nam ile pamięci będzie
                     potrzebne (pod suwakiem którym przypisujemy ilość
                     pamięci widnieje kolorowy pasek, gdzie kolor
                     zielony oznacza wystarczającą ilość Pamięci).

                 b.  Ilość monitorów: Możliwość dodania wirtualnych
                     monitorów do maszyny. Wspierane jest do 8
                     wirtualnych monitorów i każdy monitor jest osobnym
                     okienkiem na pulpicie hosta. W trybie
                     pełnoekranowym wykorzystują fizyczne monitory hosta

                 c.  Scale Factor (Współczynnik skali): Pozwala na
                     skalowanie rozmiaru ekranu, w przypadku wielu
                     monitorów można zarządzać tą wartością dla każdego
                     monitora z osobna lub ustawić domyślny współczynnik
                     dla wszystkich monitorów.

                 d.  Kontroler graficzny:

                     i.  VBoxSVGA -- Domyślny dla maszyn uruchamiających
                         windowsa 7 lub nowszego, ten kontroler poprawia
                         wydajność akceleracji 30 względem starszego
                         VBoxVGA

                     ii. VBoxVGA -- Zalecane jest używanie tego
                         kontrolera w przypadku starszych systemów
                         operacyjnych ( Oracle Solaris lub windows
                         starszy niż 7). Akceleracja 3D nie jest
                         wspierana przez ten kontroler

                     iii. VMSVGA: Kontroler emulijący urządzenie
                          graficzne VMware SVGA. Standardowy kontroler
                          graficzny dla Linuxa

                     iv. Brak (None) -- Nie emuluje żadnego kontrolera
                         graficznego.

                 e.  Włącz akcelerację 3D -- Możliwe jest włączenie
                     akceleracji gdy system zainstalowany w maszynie
                     wirtualnej posiada paczkę dodatków gościa (jest to
                     paczka pakietów które zapewniają lepszą integrację
                     wirtualizowanego systemu ze środowiskiem
                     wirtualizacyjnym (virtualbox)). W skrócie --
                     akceleracja umożliwia sprawniejsze renderowanie
                     grafiki 3D wykorzystującej technologie OpenGL lub
                     Direct3D 8/9. Zamiast emulowania tych technologii
                     virtualbox wykorzysta hardware maszyny hosta co
                     zwiększy wydajność.

             2.  Zdalny pulpit:

                 a.  W tej zakładce można uruchomić serwer zdalnego
                     pulpitu, do którego połączyć się można z poziomu
                     dowolnego oprogramowania wykorzystującego protokół
                     RDP.

             3.  Nagrywanie:

                 a.  Virtualbox daje możliwość nagrywania ekranu oraz
                     dźwięku podczas korzystania z wirtualnej maszyny.
                     Może to zostać włączone oraz wyłączone w trakcie
                     pracy wirtualnej maszyny. Zmienić można takie
                     parametry jak:

                     i.  Tryb nagrywania (tylko wideo, tylko audio,
                         wideo i audio),

                     ii. Ścieżka pliku (w jakiej zostanie zapisany plik
                         z nagraniem),

                     iii. Rozmiar klatki (Rozdzielczość nagrania w
                          pikselach),

                     iv. Ilość klatek na sekundę,

                     v.  Jakość wideo (możliwość ustawienia bitrate'u
                         nagrania w kilobitach na sekundę)

                     vi. Jakość audio,

                     vii. Ekrany (możliwość wybrania, jakie ekrany będą
                          nagrywane).

> Podczas zmiany parametrów wyświetlany jest szacowany rozmiar pliku
> wyjściowego.

iv. Pamięć -- w tej sekcji można dodać nowe wirtualne dyski twarde,
    płyty CD/DVD, dyski fizyczne, obrazy ISO i inne urządzenia
    magazynowania do wirtualnej maszyny (tutaj można dodać również
    nośnik z obrazem systemu).

v.  Dźwięk -- Możliwość podłączenia wirtualnej karty dźwiękowej do
    maszyny oraz ustawienia, czy dźwięk powinien być odtwarzany na
    systemie hosta. Można

    1.  Sterownik dźwięku gospodarza:

        a.  Sterownik który jest wykorzystywany przez virtualbox na
            systemie hosta. Domyślna opcja wybiera automatycznie
            najlepszy wybór dla platformy hosta. Daje to możliwość
            przenoszenia maszyny pomiędzy różnymi platformami bez
            konieczności zmiany sterownika dźwięku.

        b.  Dla linuxa zalecane jest OSS, ALSA lub PulseAudio, dla
            nowszych dystrybucji preferowany jest subsystem PulseAudio.

        c.  Dla Oracle Solaris wspierany jest jedynie subsystem OSS

    2.  Kontroler Audio -- możliwość wyboru emulacji kontrolera audio
        między Intel AC'97, Intel HD Audio oraz SoundBlaster 16.

    3.  Włącz wyjście dźwięku -- włącza wyjście dźwięku dla maszyny
        wirtualnej

    4.  Włącz wejście dźwięku -- włącza wejście dźwięku dla maszyny
        wirtualnej

vi. Sieć - sekcja Sieć umożliwia skonfigurowanie tego, jak virtualbox
    prezentuje wirtualne karty sieciowe dla maszyny wirtualnej oraz jak
    będą one operować:

    1.  Podłączona do: Każda karta sieciowa może zostać skonfigurowana
        aby operować w poniższych trybach:

        a.  Niepołączona -- w tym trybie virtualbox przedstawia maszynie
            wirtualnej kartę sieciową która nie ma połączenia (tak jakby
            kabel Ethernet nie był podłączony do karty).

        b.  NAT -- domyślny tryb karty sieciowej, jeśli użytkownik ma w
            zamiarze zwyczajnie przeglądać sieć internet czy pobierać
            pliki z poziomu maszyny wirtualnej.

        c.  Sieć NAT -- Jest to rodzaj sieci wewnętrznej, która zezwala
            na połączenia wychodzące. Działa ona podobnie jak router
            domowy. Do łatwiejszego korzystania z tej opcji wymagane
            będzie uruchomienie w utworzonej sieci serwera DHCP.

        d.  Mostkowana karta sieciowa (bridged) -- opcja przeznaczona do
            bardziej zaawanowanych potrzeb, takich jak symulacje
            działania sieci czy uruchamianie serwerów w systemie
            zainstalowanym w maszynie wirtualnej. To ustawienie sprawia,
            że VirtualBox łączy się do jednej z zainstalowanych u hosta
            kart sieciowych i przeprowadza wymianę pakietów
            bezpośrednio, omijając system hosta.

        e.  Sieć wewnętrzna -- ta opcja może zostać wykorzystana do
            stworzenia sieci pomiędzy usługami, która będzie widoczna
            dla wybranych maszyn wirtualnych ale nie dla programów
            działających na systemie hosta lub gdziekolwiek na zewnątrz.

        f.  Karta sieci izolowanej (host-only) -- może zostać
            wykorzystane do stworzenia sieci zawierającej hosta oraz
            zestaw maszyn wirtualnych, bez potrzeby fizycznego
            interfejsu sieciowego u hoasta (w zamian za to tworzony jest
            interfejs sieci wirtualnej podobny do interfejsu loopback,
            który dostarcza połączenie między maszynami wirtualnymi i
            hostem)

        g.  Cloud Network -- Może zostać użyte do połączenia lokalnej
            maszyny wirtualnej z podsiecią w zdalnej usłudze chmurowej.

        h.  Rodzajowy sterownik -- rzadko używane tryby które korzystają
            z tego samego interfejsu sieciowego umożliwiając
            użytkownikowi wybór sterownika który może zostać dołączony
            do virtualboxa lub być dystrybuowany w pakiecie rozszerzeń.
            Dostępne są poniższe pod-tryby:

            i.  Tunel UDP : Służący do bezpośredniego i łatwego łączenia
                maszyn wirtualnych działających na różnych hostach
                poprzez istniejącą infrastrukturę sieciową

            ii. VDE (Wirtualny Rozproszony Ethernet): Używany do
                połączenia switcha VDE na hoście opartym o Linuxa lub
                FreeBSD. Obecnie ta opcja wymaga własnoręcznie
                zbudowanego virtualboxa, gdyż gotowe paczki od Oracle
                jej nie posiadają.

vii. Porty Szeregowe -- ta sekcja daje możliwość zwirtualizowania portów
     szeregowych dla maszyny wirtualnej. Można skonfigurować taki port
     na przykład w celu stworzenia dość prymitywnej sieci null-modem w
     razie gdyby Ethernet miałby być niedostępny. Wykorzystywane jest to
     również przez deweloperów oprogramowania do debugowania kernela,
     gdyż przeważnie oprogramowanie do przeprowadzania takiego
     debugowania działa poprzez porty szeregowe.

viii. USB -- W tej sekcji można skonfigurować obsługę USB przez
      virtualbox

      1.  Virtualbox ma możliwość zezwolenia maszynom wirtualnym na
          bezpośredni dostęp do urządzeń USB hosta. Virtualbox pozwala
          nawet na podłączenie zdalnego USB do maszyn wirtualnych
          poprzez dodatek zdalnego pulpitu (VRDE).

      2.  Do wyboru mamy kontrolery które oferują różne wspracie:

          a.  OHCI (USB 1.1)

          b.  EHCI (kontroler USB 2.0 obsługujący również kompatybilność
              wsteczną z OHCI)

          c.  xHCI (kontroler dla USB 3.1 Gen 1 wspierający wszystkie
              poprzednie prędkości USB)

      3.  Filtry urządzeń USB -- tutaj możemy ustawić, które konkretnie
          urządzenia będą automatycznie podłączane do maszyny wirtualnej

ix. Udostępniane foldery -- te katalogi umożliwiają prostą wymianę
    danych pomiędzy maszyną wirtualną a hostem. Funkcja ta wymaga
    zainstalowanych dodatków gościa w systemie zainstalowanym na
    maszynie wirtualnej.

x.  Interfejs Użytkownika -- Ta sekcja umożliwia zmianę pewnych aspektów
    interfejsu danej maszyny wirtualnej, takich jak widoczność górnego
    paska menu czy widoczność „Mini ToolBar".

```{=html}
<!-- -->
```
5.  Teraz możemy uruchomić maszynę wirtualną (poniższe kroki zakładają,
    że w ustawieniach maszyny w sekcji Pamięć został dodany nośnik z
    obrazem systemu Debian 12):

    a.  Domyślnie przy nowej maszynie z nowym dyskiem maszyna powinna od
        razu zbootować instalację debiana. Dostępne mamy 5 opcji:

        i.  Instalacja graficzna
        		1. Graficzna, prosta metoda instalacji wspierająca instalację
        		przy użyciu klawiatury i myszy.

        ii. Instalacja (w prostszej formie)
        		1. Instalacja z prostym motywem graficznym, zdecydowanie mniej
        		wymagająca, wspierająca jedynie wejście klawiatury.

        iii. Ustawienia Zaawansowane

             1.  Graficzna instalacja w trybie eksperta
             	a) Tryb instalacji wyszczególniający wszystkie możliwe
             	opcje w procesie instalacji. Zezwala również na nawigację
             	między różnymi krokami, które nie wykonują się automatycznie
             	w domyślnej sekwencji. Wspiera mysz oraz klawiaturę.
             		

             2.  Graficzny tryb odzyskiwania
             	a) Graficzny tryb odzyskiwania służy do przywracania 
             	uszkodzonej instalacji systemu lub do naprawienia bootloadera. 
             	Pokazane zostanie kilka pierwszych ekranów instalatora w 
             	bardziej zaawansowanej grafice niż ta, jaką uświadczymy w 
             	przypadku zwykłego trybu odzyskiwania z informacją, że jest to 
             	tryb odzyskiwania. Obsługuje wejście z klawiatury i myszy. Tryb 
             	ten przejmuje "dowodzenie" nad hardware'em aby zapewnić, że 
             	dyski czy urządzenia sieciowe są dostępne w czasie naprawy. 
             	Następnie umożliwii wejście do powłoki systemu w wybranym przez 
             	użytkownika systemie plików aby przeprowadzić wymagane akcje, 
             	lub aby zainstalować ponownie bootloader.

             3.  Automatyczna instalacja graficzna

             4.  Instalacja eksperta
             	a) Tryb instalacji wyszczególniający wszystkie możliwe
             	opcje w procesie instalacji. Zezwala również na nawigację
             	między różnymi krokami, które nie wykonują się automatycznie
             	w domyślnej sekwencji. Wspiera tylko klawiaturę. Charakteryzuje
             	się prostą oprawą graficzną.

             5.  Tryb odzyskiwania
             	a) Tryb odzyskiwania służy do przywracania uszkodzonej
             	instalacji systemu lub do naprawienia bootloadera. Pokazane
             	zostanie kilka pierwszych ekranów instalatora w prostej oprawie 
             	graficznej z informacją, że jest to tryb odzyskiwania. Tryb ten 
             	obsługuje jedynie wejście z klawiatury. Tryb ten przejmuje 
             	"dowodzenie" nad hardware'em aby zapewnić, że dyski czy 
             	urządzenia sieciowe są dostępne w czasie naprawy. Następnie 
             	umożliwii wejście do powłoki systemu w wybranym przez 
             	użytkownika systemie plików aby przeprowadzić wymagane akcje, 
             	lub aby zainstalować ponownie bootloader.

             6.  Automatyczna instalacja
             	a) Automatyczna instalacja wymaga pliku preseed, który zawiera 
             	informacje o konfiguracji systemu, którą domyślnie tworzymy 
             	przez instalator. Ta metoda ma za zadanie przyspieszyć 
             	instalację debiana i powinna wymagać minimalnej ingerencji 
             	człowieka.

        iv. Menu instalatora w trybie kontrastowym (ciemne menu)
        		1. Zmiana motywu menu instalatora na ciemne z wysokim kontastem.

        v.  Instalacja z syntezatorem mowy
        		1. Jedna z opcji dostępności umożliwiająca instalację systemu 
        		użytkownikom z niepełnosprawnościami (dostępna jest jeszcze 
        		instalacja z wykorzystaniem monitora brajlowskiego )

    b.  Proces będziemy kontynuować poprzez opcję normalnej instalacji

    c.  W pierwszym kroku instalacji, instalator zapyta nas o język w
        jakim będziemy przeprowadzać instalację. Warto tutaj zostać przy
        standardowym (angielskim), gdyż w tym języku można znaleźć
        najwięcej informacji w internecie co może okazać się pomocne w
        razie problemów.

    d.  Wybieramy region w jakim znajduje się maszyna -- na jego
        podstawie system dobierze sobie serwery NTP (czasu) czy też
        ustawi lokalne repozytoria aby pakiety mogły być pobierane z
        większą prędkością.

    e.  Jeśli kombinacja twojego regionu i języka nie ma zdefiniowanego
        systemu kodowania, system o to zapyta w następnym kroku. Można
        tutaj wybrać United States -- działa on na bazie UTF-8 więc
        będzie złotym środkiem między angielskim językiem systemu a
        możliwym wystąpieniem wybranego języka.

    f.  Następnie system poprosi o wybranie schematu klawiatury.
        Wybieramy odpowiadający nam schemat klawiatury (dla Polaka
        najrozsądniejszy będzie American English)

    g.  Teraz system załaduje różne komponenty potrzebne do dalszej
        instalacji oraz wykryje dostępne urządzenia

    h.  Konfiguracja sieci:

        i.  System pyta o nazwę hosta dla naszej maszyny. Można to
            potraktować to jak imię dla naszego serwera (odradzałbym
            nazwy z nietypowymi znakami, takie jak X Æ A-12),

        ii. Nazwa domenowa: Podobnie jak w powyższym (tak, tutaj też
            lepiej nie wpisywać X Æ A-12), z tym że hostname to nazwa
            pod jaką będziemy się odwoływać do komputera na poziomie
            lokalnym, czyli z niego, a domain name to nazwa, której
            będziemy używać do odwołania do komputera z zewnątrz (np.
            można skonfigurować w lokalnej sieci serwer DNS i łączyć się
            po SSH przez nazwę domenową),

    i.  Konfiguracja użytkowników

        i.  Zaczynamy od ustawienia hasła do roota -- użytkownika o
            najwyższych możliwych dostępach.

        ii. Następnie tworzymy użytkownika -- ten użytkownik będzie
            wykorzystywany domyślnie. Odradza się korzystania z konta
            root cały czas, gdyż można coś nie chcący zepsuć.

            1.  Podajemy prawdziwą nazwę użytkownika (np. Imię). Ta
                nazwa będzie używana na przykład do wysyłania emaili
                jako ten użytkownik. Instalator sam doradza, że
                rozsądnym wyborem będzie pełna nazwa użytkownika (np.
                Imię i nazwisko),

            2.  Podajemy Username -- to jest już bardziej ksywka
                użytkownika choć system zaleca aby tutaj wpisać imię
                użytkownika. Nazwa użytkownika powinna zaczynać się od
                małej litery po której może nastąpić dowolna kombinacja
                małych liter oraz cyfr,

            3.  Ustawiamy hasło dla użytkownika

        iii. Instalator doładowuje kolejne komponenty i wykrywa
             zainstalowane dyski

        iv. Przechodzimy do partycjonowania dysków -- prawdopodobnie
            najważniejszy krok podczas instalacji. Do wyboru mamy kilka
            opcji, z czego większość to partycjonowanie z asystą
            (Guided, które dają możliwość wykorzystania dostępnej
            przestrzeni, wykorzystania całego dysku, wykorzystania
            całego dysku i ustawienia LVM oraz wykorzystania całego
            dysku i ustawienia szyfrowanego LVM) i tylko jedna to opcja
            manualna, z której będziemy korzystać w następnych krokach,

            1.  Na ekranie partycjonowania Manualnego widzimy opcje
                konfiguracji dysków (ustawienie software RAID,
                ustawienie Logical Volume Managera (LVM), konfiguracja
                szyfrowanych woluminów oraz konfiguracja zdalnych
                wolumenów iSCSI), niżej widzimy dostępne dyski twarde.
                Widać pod jaki interfejs podłączony jest dysk, numer
                kontrolera pod jaki jest on podłączony, numer kanału w
                tym kontrolerze oraz numer urządzenia na tym kanale (np.
                SCSI2 (0,0,0)) oraz nazwę urządzenia (np. sda).

            2.  Partycjonowanie można przeprowadzić na wiele sposobów. W 
            graficznym instalatorze debiana 12 dostępne są poniższe systemy 
            plików:

                a.  Ext2, ext3, ext4 -- różne generacje systemu ext,
                    gdzie 2 nie miała możliwości journalingu co może
                    prowadzić do zwiększonego ryzyka utraty danych w
                    przypadku awarii oraz oferuje dobre osiągi dla
                    małych partycji i prostych zastosowan; 3 generacja
                    jest właściwie rozszerzeniem dla 2 generacji --
                    dodaje dziennikowanie aby chronić dane przed utratą
                    w przypadku awarii oraz jest wstecznie kompatybilny
                    z 2 generacją. Partycja ext3 może być montowana jako
                    ext2 na starszych systemach. Generacja 4 umożliwia
                    wsparcie plików 8 razy większych niż ext 3 i 2,
                    dzięki czemu jeden plik może ważyć do 16TB. Oprócz
                    nowych funkcji charakteryzuje się również wyższą
                    wydajnością operacji zapisu i odczytu jak i
                    wprowadza różne tryby alokacji bloków. System plików 
                    ext4 nie jest kompatybilny ze swoimi poprzednikami.

                b.  Jfs -- system plików z dziennikowaniem

                c.  Xfs -- skalowalny system plików z dziennikowaniem

                d.  FAT16, FAT32 -- stare, ograniczone systemy plików

                e.  Btrfs -- nowoczesny system plików charakteryzujący
                    się wysoką niezawodnością i elastycznością z
                    mechanizmami kontroli integralności danych, kopiami
                    migawkowymi tworzonymi w czasie rzeczywistym oraz
                    wsparciem dla RAID i innymi przydatnymi
                    funkcjonalnościami.
				
			Z poziomu powłoki systemu możemy sformatować partycje do wielu 
			innych systemów plików. Takich jak reiserfs (dziennikowany system 
			plików działający bardzo dobrze z małymi plikami, maksymalna waga 
			pliku to 1exabajt), FAT (przestarzały system plików dedykowany pod 
			systemy MS-DOS i wczesne systemy Windows), zfs (zaawansowany system 
			plików charakteryzujący się wysoką redundancją, oferujący 
			zaawansowane możliwości dla efektywnego zarządzania przestrzenią 
			dyskową).

            3.  To w jaki sposób podzielimy dysk na partycje musi być
                bardzo dobrze przemyślane. Warto zadbać o możliwość
                rozbudowania systemu w przyszłości. Tutaj na pomoc może
                nam przyjść LVM, którego wykorzystamy w kolejnych
                krokach

                a.  Tworzymy LVM z grupy wolumenów składającej się z
                    jednego wolumenu który ma wielkość prawie całego
                    dysku (warto zostawić 1 do 2 GB na fizyczne partycje
                    przeznaczone na partycję EFI (konieczna jeśli
                    maszynę uruchamiamy z EFI zamiast BIOS) oraz pod
                    /boot.

                b.  Tworzymy logiczne wolumeny -- jeden dla /home, drugi
                    dla /usr, trzeci dla /var, czwarty dla /tmp, piąty
                    dla reszty (/) oraz jeszcze jeden pod SWAP.
                    Teoretycznie lepiej jest zrobić oddzielny wolumen
                    dla /usr/local oraz jeśli planujemy uruchomić serwer
                    email na tej maszynie -- oddzielny wolumen dla
                    /usr/mail. Na potrzeby tej instrukcji wystarczy nam
                    zbiorczy wolumen dla /usr. Pamiętajmy o odpowiedniej
                    ilości dla swap -- najlepiej jest stosować do zasady
                    która mówi, że jeśli pamięci RAM jest mniej niż 2GB
                    to swap powinien mieć 2 razy więcej przestrzeni niż
                    RAM, a jeżeli pamięci RAM jest więcej niż 2GB, to
                    przestrzeń SWAP powinna być rozmiaru RAM + 2GB.
                    Nazewnictwo logicznych wolumenów jest indywidulane,
                    ale warto jest robić to na zasadzie \<nazwa
                    grupy\>-\<przeznaczanie\> (np. STORAGE1-home).

                c.  Dla każdego utworzonego logicznego wolumenu
                    wybieramy system plików oraz ustawiamy miejsce
                    montowania. Na przykład dla logicznej partycji
                    przygotowanej pod /home ustawiamy system plików
                    btrfs oraz miejsce montowania - /home, dla logicznej
                    partycji przygotowanej pod swap wybieramy z listy
                    swap area a dla partycji dla EFI -- wybieramy EFI
                    system partition.

                d.  Trzeba zauważyć opcje montowania -- są to różne
                    flagi, którymi możemy dostroić działanie systemu
                    plików. W przypadku btrfs mamy do wyboru:

                    i.  Noatime -- flaga ta wyłącza aktualizowanie czasu
                        ostatniego dostępu do pliku. Często takie
                        informacje nie są nam potrzebne, więc można je
                        wyłączyć aby usprawnić działanie systemu plików

                    ii. Nodiratime -- podobnie jak powyżej, tylko że
                        dotyczy czasu ostatniego dostępu do katalogu

                    iii. Relatime -- podobna opcja montowania do
                         noatime, ale oferuje łagodniejsze podejście --
                         w przypadku relatime atrybut atime jest
                         aktualizowany jedynie wtedy, gdy dane zostały
                         odczytane, a czas ostatniego dostępu jest
                         starszy niż czas ostatniej modyfikacji lub
                         tworzenia pliku. Oznacza to, że atime zostanie
                         zaktualizowany tylko wtedy, kiedy modyfikacja
                         pliku nastąpiła po jego ostatnim odczycie

                    iv. Nodev --  Udział zamontowany z tą flagą ma 
                        wyłączoną interpretację specjalnych urządzeń 
                        blokowych (plików urządzeń).


                    v.  Nosuid -- zapobiega wykonywania plików z
                        ustawionym bitem SUID lub SGID z tego wolumenu.
                        Bity te umożliwiają uruchamianie programów z
                        uprawnieniami użytkownika lub grupy właściciela
                        pliku. Te dwa bity są wówczas po prostu
                        ignorowane.

                    vi. Noexec -- zapobiega wykonywania plików z danego
                        wolumenu. Od nosuid wyróżnia tę opcję to, że nie
                        zezwala na wykonywanie ogólnie, nie tylko dla
                        plików z ustawionym bitem SUID lub SGID.

                    vii. Ro -- montowanie partycji tylko do odczytu, nie
                         można na niej wykonywać żadnej operacji zapisu.

                    viii. Sync -- system plików będzie działał w trybie
                          synchronicznym. Oznacza to, że system plików
                          będzie wykonywał operacje zapisu
                          synchronicznie, czyli zapisywane dane będą
                          zapisywane natychmiast na dysku fizycznym. W
                          efekcie system plików nie opiera się na
                          buforach w pamięci podręcznej i gwarantuje, że
                          dane są zapisane na dysku przed zakończeniem
                          operacji zapisu.

                    ix. Usrquota -- opcja używana w celu włączenia
                        kontroli kontyngentu użytkownika dla danego
                        systemu plików. Daje to administratorowi
                        ustalenie limitów dla indywidualnych
                        użytkowników na danej partycji. Te limity mogą
                        dotyczyć wielkości zajętego miejsca na dysku,
                        liczby plików lub innych kryteriów.

                    x.  Grpquota -- podobna opcja do usrquota, tylko że
                        dłuży do określania limitów dla grup
                        użytkowników.

                e.  Kolejna opcja to label -- nie jest to nic innego jak
                    możliwość ustawienia przyjaznej nazwy dla tego
                    wolumenu.

            4.  Kończymy partycjonowanie wybierając „Finish partitioning
                and write changes to disk" i następnie wyrażamy zgodę na
                zastosowanie zmian na dysku. Instalator przeprowadzi
                formatowanie partycji a następnie przejdzie do
                instalacji systemu. W trakcie instalacji instalator
                zapyta się, czy przeprowadzić skanowanie w poszukiwaniu
                nowych mediów instalacyjnych.

            5.  Następnie przechodzimy do konfiguracji menedżera
                pakietów. Instalator zapyta, jakie źródło lustrzane
                wybrać. Dla najlepszego połączenia i najwyższych
                prędkości warto wybrać kraj w jakim znajduje się maszyna
                i wybrać serwery z których będziemy pobierać pakiety.
                Później będzie również pytanie o chęć brania udziału w
                badaniach statystycznych dotyczących pobieranych
                pakietów. Opcjonalnie może pojawić się pytanie, z której
                instalki kernela skorzystać (jeśli dostępne jest więcej
                niż jedna) oraz jakie sterowniki zainstalować (domyślną
                paczkę czy wymagane).

            6.  Po konfiguracji menedżera pakietów apt instalator zapyta
                nas czy chcemy doinstalować dodatkowe oprogramowanie,
                takie jak serwer SSH, httpd czy środowisko graficzne.

            7.  Dostępne z poziomu instalatora środowiska graficzne:
            			a) GNOME
            				i. Wymagania sprzętowe:
            					1. Dwurdzeniowy procesor 2GHz
            					2. 4GB Pamięci RAM
            					3. 20GB miejsca na dysku
            					
            				ii. Charakterystyka:
            					1. Efektowny
            					2. Intuicyjny
            					3. Integracja z różnymi oprogramowaniami
            					4. Możliwość instalacji rozszerzeń
            					5. Stale rozwijany o nowe funkcje i zabezpieczenia
            					6. Wybitny w przypadku jednego monitora 		
            					(subiektywna opinia)
            						
            			b) Xfce 
            				i. Wymagania sprzętowe:
            					1. Procesor: 1GHz+
            					2. Pamięć RAM: 512MB na czas instalacji, 
            					zainstalowany 128mb
            					3. Przestrzeń dyskowa ~1,5GB
            					
            				ii. Charakterystyka:
            					1. Szybki
            					2. Niskie zapotrzebowanie na zasoby
            					3. Prosty w obsłudze
            					4. Prosty wygląd
            					
            			c) KDE Plasma
            				i. Wymagania sprzętowe:
            					1. Procesor: 2GHz 64bit
            					2. RAM: 2 GB
            					3: Przestrzeń dyskowa: 10GB
            					
            				ii. Charakterystyka:
            					1. Efektowny
            					2. Intuicyjny
            					3. Integracja z różnymi oprogramowaniami
            					4. Bardzo dobra zintegrowana aplikacja 
            					terminala (subiektywna opinia).
            			
            			d) Cinnamon
            				i. Wymagania:
            					1. Procesor: 2GHz 2 rdzenie
            					2. Pamięć RAM: 2GB
            					3. Przestrzeń dyskowa: 20GB
            					
            				ii. Charakterystyka:
            					1. Stylowy
            					2. Doświadczenie zbliżone do windowsa
            					3. Intuicyjny
            					4. Prosty w obsłudze
            					
            			e) MATE
            				i. Wymagania:
            					1. Procesor: 1GHz
            					2. RAM: 1GB
            					3. Przestrzeń dyskowa: 8GB
            					
            				ii. Charakterystyka:
            					1. Szybki
            					2. Minimalistyczny
            					3. Mieszanka MacOS i Windowsa z dodatkiem
                                cech charakterystycznych dla środowisk
                                linuxowych (subiektywna opinia).
            				
            			f) LXDE
                            i. Wymagania:
                                1. Procesor: Tak (Pentium II)
                                2. Ram: Tak (45MB)
                                3. Przestrzeń dyskowa: 200MB
                            ii. Charakterystyka:
                                1. Lekki
                                2. Szybki
                                3. Prosty w użytku
                                4. Odpowiedni dla starych maszyn
            			
            			g) LXQt
                            i. Wymagania:
                                1. Procesor: 512MHz
                                2. Ram: 512MB
                                3. Przestrzeń dyskowa: 6GB
                            ii. Charakterystyka:
                                1. Modularny
                                2. Duże możliwości personalizacji
                                3. Możliwość instalacji dodatków

            8.  Gdy instalacja przebiegnie pomyślnie instalator
                zaproponuje restart maszyny i zbootowanie systemu. Jeśli
                nie instalowaliśmy żadnego środowiska graficznego,
                system przywita nas tekstem informującym o wersji
                debiana i prośbą o podnie nazwy użytkownika a następnie
                o jego hasło.

# Adnotacja na koniec
- Całe rozwiązanie zadania zostało napisane przezemnie od zera.
- Do pomocy jakiej potrzebowałem na wielu etapach wykorzystywałem dokumentacje virtualboxa i debiana. Dodatkowo zostały wykorzystane dokumentacje wymienionych środowisk graficznych.
- Części z systemami plików i opcjami montowań były konsultowane z chatem gpt (wolałem żeby mi to po ludzku opisał zamiast czytać dokumentacje każdego systemu plików z osobna).
- Całość była pisana w taki sposób, żebym mógł się do tego pliku w przyszłości odnieść aby przypomnieć sobie pewne informacje (np. odnośnie flag montowania).
- Szczególnie nowymi były dla mnie informacje właśnie odnośnie systemów plików – wiedziałem że istnieją różne systemy plików i że się różnią ale to zadanie dało mi większą wiedzę na temat różnic między nimi. Nowe dla mnie też są opcje montowań, z którymi się już wcześniej spotkałem (nawet używałem) ale nie wiedziałem o tak wielu.
- Z pewnością nowe informacje przydadzą mi się do stawiania nowych maszyn (które sobie hobbystycznie tworzę na różne potrzeby).