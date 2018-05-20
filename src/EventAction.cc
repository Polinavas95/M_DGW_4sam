//
// Created by student on 27.04.18.
//
#include <fstream>
#include <regexp.h>
#include "EventAction.hh"
#include "StepAction.hh"
using namespace std;
//class StepAction;
StepAction obj;

EventAction::EventAction(RunAction* runAct) :run(runAct) {

}

EventAction::~EventAction() {

}

void EventAction::BeginOfEventAction(const G4Event* anEvent) {
    EnergyDep = 0;
}

void EventAction::EndOfEventAction(const G4Event* anEvent) {

    ofstream fout("../result.txt",
                  std::ios_base::app); //Автоматически переставляет указатель текущего символа потока в конец
    fout.clear();
    for (auto it: *res) {
        fout << it.first << " | " << it.second << "\n";
    }
    for (auto it: *res) {
  if((it.second <= 0.5) && (obj.getMel()==2)){

    run->AddEnDep(EnergyDep);}}
}

void EventAction::AddEvent(G4String Name,G4double energy){
    if( res->find(Name) == res->end()) {
        res->emplace(Name, energy);//функция принимает параметры, которые будут перенаправлены конструктору объекта, хранящегося в контейнере
    }
    res->find(Name)->second += energy;
}
