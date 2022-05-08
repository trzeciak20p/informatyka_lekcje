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

?>