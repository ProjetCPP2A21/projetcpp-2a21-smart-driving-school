-- ========================================
-- SOLUTION 1 : Ajouter une colonne ID_MONITEUR à la table APPRENANTS
-- ========================================
-- Cette solution est simple mais crée une relation 1-to-many (un apprenant = un moniteur)
-- Utilisez cette solution si chaque apprenant n'a qu'un seul moniteur

-- Étape 1 : Ajouter la colonne ID_MONITEUR à APPRENANTS
ALTER TABLE APPRENANTS ADD ID_MONITEUR NUMBER;

-- Étape 2 : Créer une contrainte de clé étrangère (optionnel mais recommandé)
ALTER TABLE APPRENANTS 
ADD CONSTRAINT FK_APPRENANT_MONITEUR 
FOREIGN KEY (ID_MONITEUR) REFERENCES MONITEUR(ID);

-- Étape 3 : Mettre à jour les données existantes (remplacer NULL par un ID de moniteur valide)
-- Remplacez 1 par l'ID d'un moniteur existant ou laissez NULL si pas encore assigné
-- UPDATE APPRENANTS SET ID_MONITEUR = 1 WHERE ID_MONITEUR IS NULL;

-- ========================================
-- SOLUTION 2 : Créer une table de liaison (RECOMMANDÉE)
-- ========================================
-- Cette solution est meilleure car elle permet une relation many-to-many
-- (un apprenant peut avoir plusieurs moniteurs, un moniteur peut avoir plusieurs apprenants)

-- Étape 1 : Créer la table de liaison ENSEIGNEMENT
CREATE TABLE ENSEIGNEMENT (
    ID_ENSEIGNEMENT NUMBER PRIMARY KEY,
    ID_MONITEUR NUMBER NOT NULL,
    ID_APPRENANT NUMBER NOT NULL,
    DATE_DEBUT DATE,
    DATE_FIN DATE,
    CONSTRAINT FK_ENSEIGNEMENT_MONITEUR FOREIGN KEY (ID_MONITEUR) REFERENCES MONITEUR(ID),
    CONSTRAINT FK_ENSEIGNEMENT_APPRENANT FOREIGN KEY (ID_APPRENANT) REFERENCES APPRENANTS(ID_APPRENANT),
    CONSTRAINT UK_ENSEIGNEMENT UNIQUE (ID_MONITEUR, ID_APPRENANT)
);

-- Étape 2 : Créer une séquence pour l'ID (Oracle)
CREATE SEQUENCE SEQ_ENSEIGNEMENT
START WITH 1
INCREMENT BY 1
NOCACHE;

-- Étape 3 : Créer un trigger pour auto-incrémenter l'ID (optionnel)
CREATE OR REPLACE TRIGGER TRG_ENSEIGNEMENT_ID
BEFORE INSERT ON ENSEIGNEMENT
FOR EACH ROW
BEGIN
    IF :NEW.ID_ENSEIGNEMENT IS NULL THEN
        :NEW.ID_ENSEIGNEMENT := SEQ_ENSEIGNEMENT.NEXTVAL;
    END IF;
END;
/

-- Étape 4 : Insérer des données d'exemple (remplacez par vos vraies données)
-- INSERT INTO ENSEIGNEMENT (ID_MONITEUR, ID_APPRENANT, DATE_DEBUT) 
-- VALUES (1, 1, SYSDATE);
-- INSERT INTO ENSEIGNEMENT (ID_MONITEUR, ID_APPRENANT, DATE_DEBUT) 
-- VALUES (1, 2, SYSDATE);

-- ========================================
-- SOLUTION 3 : Utiliser la table AFFECTER existante (si elle lie MONITEUR à APPRENANTS)
-- ========================================
-- Si la table AFFECTER peut être utilisée pour lier MONITEUR à APPRENANTS
-- via les véhicules, vous pouvez modifier AFFECTER pour inclure ID_APPRENANT

-- Option A : Ajouter ID_APPRENANT à AFFECTER
-- ALTER TABLE AFFECTER ADD ID_APPRENANT NUMBER;
-- ALTER TABLE AFFECTER 
-- ADD CONSTRAINT FK_AFFECTER_APPRENANT 
-- FOREIGN KEY (ID_APPRENANT) REFERENCES APPRENANTS(ID_APPRENANT);

-- Option B : Créer une nouvelle table qui lie AFFECTER à APPRENANTS via véhicule
-- CREATE TABLE APPRENANT_VEHICULE (
--     ID_APPRENANT NUMBER,
--     IMMATRICULATION VARCHAR2(20),
--     CONSTRAINT FK_APV_APPRENANT FOREIGN KEY (ID_APPRENANT) REFERENCES APPRENANTS(ID_APPRENANT),
--     CONSTRAINT FK_APV_VEHICULE FOREIGN KEY (IMMATRICULATION) REFERENCES VEHICULES(IMMATRICULATION)
-- );

-- ========================================
-- VÉRIFICATION
-- ========================================
-- Après avoir exécuté une des solutions ci-dessus, vérifiez avec :

-- Pour Solution 1 :
-- SELECT COLUMN_NAME, DATA_TYPE FROM USER_TAB_COLUMNS 
-- WHERE TABLE_NAME = 'APPRENANTS' AND COLUMN_NAME = 'ID_MONITEUR';

-- Pour Solution 2 :
-- SELECT * FROM USER_TABLES WHERE TABLE_NAME = 'ENSEIGNEMENT';
-- SELECT * FROM ENSEIGNEMENT;

