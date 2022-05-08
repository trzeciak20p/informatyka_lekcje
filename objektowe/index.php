<?php

class Student_public{

    public string $imie;
    public string $nazwisko;
    public string $klasa;
    public int $nr_w_dzienniku;

    public function __construct(string $imie, string $nazwisko, string $klasa, int $nr_w_dzienniku){
        $this -> imie = $imie;
        $this -> nazwisko = $nazwisko;
        $this -> klasa = $klasa;
        $this -> nr_w_dzienniku = $nr_w_dzienniku;
    }
}

$student = new Student_public("Jan", "Kowalski", "2I", 37);
$student2 = new Student_public("Stefan", "Batory", "3I", 12);
$student2 -> imie = "Jacek";
$student2 -> nazwisko = "Placek";
$student2 -> nazwisko = "Kowal";
$student2 -> klasa = "2B";

echo $student -> imie . " ". $student -> nazwisko ; 

echo "<br><br><br>";

class Student_php8{

    public function __construct(
        public string $imie,
        public string $nazwisko,
        public string $klasa,
        public int $nr_w_dzienniku,
    ) {}
    
}

$student3 = new Student_php8("Marcin", "Kowalski", "3A", 45);
$student3 -> imie = "Zenek";
echo $student -> imie ." ". $student -> nazwisko ." klasa: ". $student3 -> klasa; 

echo "<br><br><br>";

class Student_private{

    private string $imie;
    private string $nazwisko;
    private string $klasa;
    private int $nr_w_dzienniku;

    public function _constructor(string $imie, string $nazwisko, string $klasa, string $nr_w_dzienniku){
        $this -> imie = $imie;
        $this -> nazwisko = $nazwisko;
        $this -> klasa = $klasa;
        $this -> nr_w_dzienniku = $nr_w_dzienniku;
    }

    public function setAll(string $imie, string $nazwisko, string $klasa, string $nr_w_dzienniku){
        $this -> imie = $imie;
        $this -> nazwisko = $nazwisko;
        $this -> klasa = $klasa;
        $this -> nr_w_dzienniku = $nr_w_dzienniku;
    }
    public function displayAll(){
        echo "Imie: ". $this -> imie .", nazwisko: ". $this -> nazwisko .", klasa: ". $this -> klasa .", numer w dzienniku: ". $this -> nr_w_dzienniku ;
    }

    public function setName(string $imie){
        $this -> imie = $imie;
    }
    public function setSurename(string $nazwisko){
        $this -> nazwisko = $nazwisko;
    }
    public function setClass(string $klasa){
        $this -> klasa = $klasa;
    }
    public function setNumber(string $nr_w_dzienniku){
        $this -> nr_w_dzienniku = $nr_w_dzienniku;
    }

    public function getName(){
        return $this -> imie;
    }
    public function getSurename(){
        return $this -> nazwisko;
    }
    public function getClass(){
        return $this -> klasa;
    }
    public function getNumber(){
        return $this -> nr_w_dzienniku;
    }

}

$student4 = new Student_private();
$student4 -> setAll("Jan", "Kowalski", "2I", 37);
$student4 -> displayAll();
$student4 -> setNumber(105);
$student4 -> getNumber();



?>