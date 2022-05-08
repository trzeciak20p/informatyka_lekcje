<?php

class Student_public{

    public string $imie;
    public string $nazwisko;
    public string $klasa;
    public int $nr_w_dzienniku;

    public function _constructor(){

    }
}

$student = new Student("Jan", "Kowalski", "2I", 37)


class Student_php8{
    public function __construct(
        public string $imie,
        public string $nazwisko,
        public string $klasa,
        public int $nr_w_dzienniku
    ) {}
}


class Student_private{

    private string $imie;
    private string $nazwisko;
    private string $klasa;
    private int $nr_w_dzienniku;

    public function setAll(string $imie, string $nazwisko, string $klasa, string $nr_w_dzienniku){
        $this -> imie = $imie;
        $this -> nazwisko = $nazwisko;
        $this -> klasa = $klasa;
        $this -> nr_w_dzienniku = $nr_w_dzienniku;
    }
    public function displayAll(){
        echo "Imie: $this -> imie Nazwisko: $this -> nazwisko Klasa: $this -> klasa Numer w dzienniku: $this -> nr_w_dzienniku: "
    }

}


?>