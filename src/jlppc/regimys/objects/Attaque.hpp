/*
Attaque.hpp
Auteur : Jlppc
Fichier sous licence GPL-3.0
http://regimys.tk
Contient la d�finition de la classe Attaque
*/
#ifndef SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_
#define SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_

#include <iostream>
#include "../../utils/Utils.hpp"
#include "../enums/Enums.hpp"

class OpMon;
/**
Repr�sente une attaque Pok�mon
*/
//->PureVirtual
class Attaque {
	public:
		virtual ~Attaque() {}
		Attaque(std::string nom, int puissance, int type, int precision, bool special, bool status, int chanceDeCoups, bool rateJamais, int ppMax, int priorite);
		//->PureVirtual
		virtual int effetAvant(OpMon &atk, OpMon &def) = 0;
		//->PureVirtual
		virtual int effetApres(OpMon &atk, OpMon &def) = 0;
		void healPP() {pp = ppMax;}
		/**atk attaque le pok�mon def*/
		//->Final
		virtual int attack(OpMon &atk, OpMon &def);
		virtual void siEchoue(OpMon &atk, OpMon &def) {}
	protected:
		std::string nom;
		int puissance;
		int priorite;
		int precision;
		int type;
		bool special;
		bool status;
		int part = 0;
		int pp;
		int ppMax;
		/**La chance de coups critiques, en 1/nombre (Par d�faut, 16)*/
		int chanceDeCoups;
		bool rateJamais;
		/**Variable utilis�e dans effetAvant et effetApr�s*/
		int pvPerdus = 0;
};

#endif /* SRCCPP_JLPPC_REGIMYS_OBJECTS_ATTAQUE_HPP_ */
