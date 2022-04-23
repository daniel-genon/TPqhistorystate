/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
**
**
Ce fichier fait partie du module QtCore de la boîte à outils Qt.

$QT_BEGIN_LICENSE:BSD$
Utilisation de la licence commerciale
Les détenteurs de licences commerciales Qt valides peuvent utiliser ce fichier
conformément à l'accord de licence commerciale fourni avec le logiciel ou, alternativement,
conformément aux termes contenus dans un accord écrit entre vous et The Qt Company.
Pour les termes et conditions de la licence, voir https://www.qt.io/terms-conditions.
Pour de plus amples informations, utilisez le formulaire de contact à l'adresse
https://www.qt.io/contact-us.

Utilisation de la licence BSD
Vous pouvez également utiliser ce fichier selon les termes de la licence BSD comme suit :

"La redistribution et l'utilisation sous forme source et binaire, avec ou sans modification, sont autorisées sous réserve que les conditions suivantes soient .
respectées :
  * Les redistributions de code source doivent conserver l'avis de droit d'auteur ci-dessus,
    cette liste de conditions et la clause de non-responsabilité suivante.
  * Les redistributions sous forme binaire doivent reproduire l'avis de droit d'auteur ci-dessus,
    la présente liste de conditions et la clause de non-responsabilité suivante dans la documentation
    et/ou les autres documents fournis avec le logiciel.
    dans la documentation et/ou les autres documents fournis avec la distribution.
  * Ni le nom de The Qt Company Ltd ni les noms de ses contributeurs ne peuvent être utilisés
    pour approuver ou promouvoir des produits dérivés de ce logiciel sans autorisation écrite préalable.

CE LOGICIEL EST FOURNI PAR LES DÉTENTEURS DES DROITS D'AUTEUR ET LES CONTRIBUTEURS
"EN L'ÉTAT" ET TOUTE GARANTIE EXPRESSE OU IMPLICITE, Y COMPRIS, MAIS SANS S'Y LIMITER,
LES GARANTIES IMPLICITES DE QUALITÉ MARCHANDE ET D'ADÉQUATION À UN USAGE PARTICULIER,
EST REJETÉE. EN AUCUN CAS, LE TITULAIRE DU DROIT D'AUTEUR OU LES CONTRIBUTEURS NE POURRONT
ÊTRE TENUS RESPONSABLES DE TOUT DOMMAGE DIRECT, INDIRECT, ACCESSOIRE, SPÉCIAL, EXEMPLAIRE
OU CONSÉCUTIF (Y COMPRIS, MAIS SANS S'Y LIMITER, L'ACQUISITION DE BIENS OU DE SERVICES DE SUBSTITUTION,
LA PERTE D'UTILISATION, DE DONNÉES OU DE BÉNÉFICES, OU L'INTERRUPTION D'ACTIVITÉ),
QUELLE QU'EN SOIT LA CAUSE ET QUELLE QUE SOIT LA THÉORIE DE RESPONSABILITÉ, QU'IL S'AGISSE D'UN CONTRAT,
D'UNE RESPONSABILITÉ STRICTE OU D'UN DÉLIT (Y COMPRIS LA NÉGLIGENCE OU AUTRE) DÉCOULANT DE QUELQUE MANIÈRE
QUE CE SOIT DE L'UTILISATION DE CE LOGICIEL, MÊME S'ILS ONT ÉTÉ INFORMÉS DE LA POSSIBILITÉ DE TELS DOMMAGES."
$QT_END_LICENSE
**
****************************************************************************/

#include <QApplication>
//#include <QEventTransition>
#include <QMouseEventTransition>
#include <QPushButton>
#include <QStateMachine>
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>

/**************** début ajout pour test ***/
class TransMouse : public QMouseEventTransition
{
public:
    TransMouse(QObject *dobject, QEvent::Type dtype,
               Qt::MouseButton dbutton) : QMouseEventTransition( dobject, dtype, dbutton )
    {
        pobjet = static_cast<QPushButton*>(dobject);
    }

protected:
    virtual bool eventTest( QEvent *evt)
    {
        if (!QMouseEventTransition::eventTest(evt)) return false;
//        QMessageBox::information(NULL,"transition OK","Changement de bouton");
        return true;
    }
    virtual void onTransition(QEvent *)
    {
        if(button()==Qt::LeftButton)
          setButton(Qt::RightButton);
        else
          setButton(Qt::LeftButton);
    }

private:
    QPushButton *pobjet;

};
/**************** fin ajout pour test ***/


//! [0]
class Window : public QWidget
{
public:
    Window(QWidget *parent = nullptr)
        : QWidget(parent)
    {
        QPushButton *button = new QPushButton(this);
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(button);
        layout->setContentsMargins(80, 80, 80, 80);
        setLayout(layout);
//! [0]

//! [1]
        QStateMachine *machine = new QStateMachine(this);

        QState *s1 = new QState();
        s1->assignProperty(button, "text", "Outside");

        QState *s2 = new QState();
        s2->assignProperty(button, "text", "Inside");
//! [1]

//! [2]
        QEventTransition *enterTransition = new QEventTransition(button, QEvent::Enter);
        enterTransition->setTargetState(s2);
        s1->addTransition(enterTransition);
//! [2]

//! [3]
        QEventTransition *leaveTransition = new QEventTransition(button, QEvent::Leave);
        leaveTransition->setTargetState(s1);
        s2->addTransition(leaveTransition);
//! [3]

//! [4]
        QState *s3 = new QState();
        s3->assignProperty(button, "text", "Pressing...");

//******** modification pour test
//        QEventTransition *pressTransition = new QEventTransition(button, QEvent::MouseButtonPress);
        TransMouse *pressTransition = new TransMouse(button,QEvent::MouseButtonPress,Qt::LeftButton);
        pressTransition->setTargetState(s3);
        s2->addTransition(pressTransition);

//******** modification pour test
//        QEventTransition *releaseTransition = new QEventTransition(button, QEvent::MouseButtonRelease);
        TransMouse *releaseTransition = new TransMouse(button,QEvent::MouseButtonRelease,Qt::LeftButton);
        releaseTransition->setTargetState(s2);
        s3->addTransition(releaseTransition);
//! [4]

//! [5]
        machine->addState(s1);
        machine->addState(s2);
        machine->addState(s3);

        machine->setInitialState(s1);
        machine->start();
    }
};
//! [5]

//! [6]
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Window window;
    window.resize(300, 300);
    window.show();

    return app.exec();
}
//! [6]
