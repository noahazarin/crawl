/*
 *  File:       randart.cc
 *  Summary:    Random and unrandom artifact functions.
 *  Written by: Linley Henzell
 *
 *  Modified for Crawl Reference by $Author$ on $Date$
 *
 *  Change History (most recent first):
 *
 *   <8>     19 Jun 99   GDL    added IBMCPP support
 *   <7>     14/12/99    LRH    random2 -> random5
 *   <6>     11/06/99    cdl    random4 -> random2
 *
 *   <1>     -/--/--     LRH    Created
 */

#include "AppHdr.h"
#include "randart.h"

#include <cstdlib>
#include <climits>
#include <string.h>
#include <stdio.h>

#include "externs.h"
#include "itemname.h"
#include "itemprop.h"
#include "stuff.h"

/*
   The initial generation of a randart is very simple - it occurs
   in dungeon.cc and consists of giving it a few random things - plus & plus2
   mainly.
*/
const char *rand_wpn_names[] = {
    " of Blood",
    " of Death",
    " of Bloody Death",
    " of Pain",
    " of Painful Death",
    " of Pain & Death",
    " of Infinite Pain",
    " of Eternal Torment",
    " of Power",
    " of Wrath",
/* 10: */
    " of Doom",
    " of Tender Mercy",
    " of the Apocalypse",
    " of the Jester",
    " of the Ring",
    " of the Fool",
    " of the Gods",
    " of the Imperium",
    " of Destruction",
    " of Armageddon",
/* 20: */
    " of Cruel Justice",
    " of Righteous Anger",
    " of Might",
    " of the Orb",
    " of Makhleb",
    " of Trog",
    " of Xom",
    " of the Ancients",
    " of Mana",
    " of Nemelex Xobeh",
/* 30: */
    " of the Magi",
    " of the Archmagi",
    " of the King",
    " of the Queen",
    " of the Spheres",
    " of Circularity",
    " of Linearity",
    " of Conflict",
    " of Battle",
    " of Honour",
/* 40: */
    " of the Butterfly",
    " of the Wasp",
    " of the Frog",
    " of the Weasel",
    " of the Troglodytes",
    " of the Pill-Bug",
    " of Sin",
    " of Vengeance",
    " of Execution",
    " of Arbitration",
/* 50: */
    " of the Seeker",
    " of Truth",
    " of Lies",
    " of the Eggplant",
    " of the Turnip",
    " of Chance",
    " of Curses",
    " of Hell's Wrath",
    " of the Undead",
    " of Chaos",
/* 60: */
    " of Law",
    " of Life",
    " of the Old World",
    " of the New World",
    " of the Middle World",
    " of Crawl",
    " of Unpleasantness",
    " of Discomfort",
    " of Brutal Revenge",
    " of Triumph",
/* 70: */
    " of Evisceration",
    " of Dismemberment",
    " of Terror",
    " of Fear",
    " of Pride",
    " of the Volcano",
    " of Blood-Lust",
    " of Division",
    " of Eternal Harmony",
    " of Peace",
/* 80: */
    " of Quick Death",
    " of Instant Death",
    " of Misery",
    " of the Whale",
    " of the Lobster",
    " of the Whelk",
    " of the Penguin",
    " of the Puffin",
    " of the Mushroom",
    " of the Toadstool",
/* 90: */
    " of the Little People",
    " of the Puffball",
    " of Spores",
    " of Optimality",
    " of Pareto-Optimality",
    " of Greatest Utility",
    " of Anarcho-Capitalism",
    " of Ancient Evil",
    " of the Revolution",
    " of the People",
/* 100: */
    " of the Elves",
    " of the Dwarves",
    " of the Orcs",
    " of the Humans",
    " of Sludge",
    " of the Naga",
    " of the Trolls",
    " of the Ogres",
    " of Equitable Redistribution",
    " of Wealth",
/* 110: */
    " of Poverty",
    " of Reapportionment",
    " of Fragile Peace",
    " of Reinforcement",
    " of Beauty",
    " of the Slug",
    " of the Snail",
    " of the Gastropod",
    " of Corporal Punishment",
    " of Capital Punishment",
/* 120: */
    " of the Beast",
    " of Light",
    " of Darkness",
    " of Day",
    " of the Day",
    " of Night",
    " of the Night",
    " of Twilight",
    " of the Twilight",
    " of Dawn",
/* 130: */
    " of the Dawn",
    " of the Sun",
    " of the Moon",
    " of Distant Worlds",
    " of the Unseen Realm",
    " of Pandemonium",
    " of the Abyss",
    " of the Nexus",
    " of the Gulag",
    " of the Crusades",
/* 140: */
    " of Proximity",
    " of Wounding",
    " of Peril",
    " of the Eternal Warrior",
    " of the Eternal War",
    " of Evil",
    " of Pounding",
    " of Oozing Pus",
    " of Pestilence",
    " of Plague",
/* 150: */
    " of Negation",
    " of the Saviour",
    " of Infection",
    " of Defence",
    " of Protection",
    " of Defence by Offence",
    " of Expedience",
    " of Reason",
    " of Unreason",
    " of the Heart",
/* 160: */
    " of Offence",
    " of the Leaf",
    " of Leaves",
    " of Winter",
    " of Summer",
    " of Autumn",
    " of Spring",
    " of Midsummer",
    " of Midwinter",
    " of Eternal Night",
/* 170: */
    " of Shrieking Terror",
    " of the Lurker",
    " of the Crawling Thing",
    " of the Thing",
    "\"Thing\"",
    " of the Sea",
    " of the Forest",
    " of the Trees",
    " of Earth",
    " of the World",
/* 180: */
    " of Bread",
    " of Yeast",
    " of the Amoeba",
    " of Deformation",
    " of Guilt",
    " of Innocence",
    " of Ascent",
    " of Descent",
    " of Music",
    " of Brilliance",
/* 190: */
    " of Disgust",
    " of Feasting",
    " of Sunlight",
    " of Starshine",
    " of the Stars",
    " of Dust",
    " of the Clouds",
    " of the Sky",
    " of Ash",
    " of Slime",
/* 200: */
    " of Clarity",
    " of Eternal Vigilance",
    " of Purpose",
    " of the Moth",
    " of the Goat",
    " of Fortitude",
    " of Equivalence",
    " of Balance",
    " of Unbalance",
    " of Harmony",
/* 210: */
    " of Disharmony",
    " of the Inferno",
    " of the Omega Point",
    " of Inflation",
    " of Deflation",
    " of Supply",
    " of Demand",
    " of Gross Domestic Product",
    " of Unjust Enrichment",
    " of Detinue",
/* 220: */
    " of Conversion",
    " of Anton Piller",
    " of Mandamus",
    " of Frustration",
    " of Breach",
    " of Fundamental Breach",
    " of Termination",
    " of Extermination",
    " of Satisfaction",
    " of Res Nullius",
/* 230: */
    " of Fee Simple",
    " of Terra Nullius",
    " of Context",
    " of Prescription",
    " of Freehold",
    " of Tortfeasance",
    " of Omission",
    " of Negligence",
    " of Pains",
    " of Attainder",
/* 240: */
    " of Action",
    " of Inaction",
    " of Truncation",
    " of Defenestration",
    " of Desertification",
    " of the Wilderness",
    " of Psychosis",
    " of Neurosis",
    " of Fixation",
    " of the Open Hand",
/* 250: */
    " of the Tooth",
    " of Honesty",
    " of Dishonesty",
    " of Divine Compulsion",
    " of the Invisible Hand",
    " of Freedom",
    " of Liberty",
    " of Servitude",
    " of Domination",
    " of Tension",
/* 260: */
    " of Monotheism",
    " of Atheism",
    " of Agnosticism",
    " of Existentialism",
    " of the Good",
    " of Relativism",
    " of Absolutism",
    " of Absolution",
    " of Abstinence",
    " of Abomination",
/* 270: */
    " of Mutilation",
    " of Stasis",
    " of Wonder",
    " of Dullness",
    " of Dim Light",
    " of the Shining Light",
    " of Immorality",
    " of Amorality",
    " of Precise Incision",
    " of Orthodoxy",
/* 280: */
    " of Faith",
    " of Untruth",
    " of the Augurer",
    " of the Water Diviner",
    " of the Soothsayer",
    " of Punishment",
    " of Amelioration",
    " of Sulphur",
    " of the Egg",
    " of the Globe",
/* 290: */
    " of the Candle",
    " of the Candelabrum",
    " of the Vampires",
    " of the Orcs",
    " of the Halflings",
    " of World's End",
    " of Blue Skies",
    " of Red Skies",
    " of Orange Skies",
    " of Purple Skies",
/* 300: */
    " of Articulation",
    " of the Mind",
    " of the Spider",
    " of the Lamprey",
    " of the Beginning",
    " of the End",
    " of Severance",
    " of Sequestration",
    " of Mourning",
    " of Death's Door",
/* 310: */
    " of the Key",
    " of Earthquakes",
    " of Failure",
    " of Success",
    " of Intimidation",
    " of the Mosquito",
    " of the Gnat",
    " of the Blowfly",
    " of the Turtle",
    " of the Tortoise",
/* 320: */
    " of the Pit",
    " of the Grave",
    " of Submission",
    " of Dominance",
    " of the Messenger",
    " of Crystal",
    " of Gravity",
    " of Levity",
    " of the Slorg",
    " of Surprise",
/* 330: */
    " of the Maze",
    " of the Labyrinth",
    " of Divine Intervention",
    " of Rotation",
    " of the Spinneret",
    " of the Scorpion",
    " of Demonkind",
    " of the Genius",
    " of Bloodstone",
    " of Grontol",
/* 340: */
    " \"Grim Tooth\"",
    " \"Widowmaker\"",
    " \"Widowermaker\"",
    " \"Lifebane\"",
    " \"Conservator\"",
    " \"Banisher\"",
    " \"Tormentor\"",
    " \"Secret Weapon\"",
    " \"String\"",
    " \"Stringbean\"",
/* 350: */
    " \"Blob\"",
    " \"Globulus\"",
    " \"Hulk\"",
    " \"Raisin\"",
    " \"Starlight\"",
    " \"Giant's Toothpick\"",
    " \"Pendulum\"",
    " \"Backscratcher\"",
    " \"Brush\"",
    " \"Murmur\"",
/* 360: */
    " \"Sarcophage\"",
    " \"Concordance\"",
    " \"Dragon's Tongue\"",
    " \"Arbiter\"",
    " \"Gram\"",
    " \"Grom\"",
    " \"Grim\"",
    " \"Grum\"",
    " \"Rummage\"",
    " \"Omelette\"",
/* 370: */
    " \"Egg\"",
    " \"Aubergine\"",
    " \"Z\"",
    " \"X\"",
    " \"Q\"",
    " \"Ox\"",
    " \"Death Rattle\"",
    " \"Tattletale\"",
    " \"Fish\"",
    " \"Bung\"",
/* 380: */
    " \"Arcanum\"",
    " \"Mud Pie of Death\"",
    " \"Transmigrator\"",
    " \"Ultimatum\"",
    " \"Earthworm\"",
    " \"Worm\"",
    " \"Worm's Wrath\"",
    " \"Xom's Favour\"",
    " \"Bingo\"",
    " \"Leviticus\"",
// Not yet possible...
/* 390: */
    " of Joyful Slaughter",
    " of ",
    " of ",
    " of ",
    " of ",
    " of ",
    " of ",
    " of ",
    " of ",
    " of ",

/* 390: */
    "\"\"",
    "\"\"",
    "\"\"",
    "\"\"",
    "\"\"",
    "\"\"",
    "\"\"",
    "\"\"",
    "\"\"",
    "\"\"",

/* 340: */
    " of ",
    " of ",
    " of ",
    " of ",
    " of ",
    " of ",
    " of ",
    " of ",
    " of ",
    " of ",

/* 200: */
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

const char *rand_armour_names[] = {
/* 0: */
    " of Shielding",
    " of Grace",
    " of Impermeability",
    " of the Onion",
    " of Life",
    " of Defence",
    " of Nonsense",
    " of Eternal Vigilance",
    " of Fun",
    " of Joy",
/* 10: */
    " of Death's Door",
    " of the Gate",
    " of Watchfulness",
    " of Integrity",
    " of Bodily Harmony",
    " of Harmony",
    " of the Untouchables",
    " of Grot",
    " of Grottiness",
    " of Filth",
/* 20: */
    " of Wonder",
    " of Wondrous Power",
    " of Power",
    " of Vlad",
    " of the Eternal Fruit",
    " of Invincibility",
    " of Hide-and-Seek",
    " of the Mouse",
    " of the Saviour",
    " of Plasticity",
/* 30: */
    " of Baldness",
    " of Terror",
    " of the Arcane",
    " of Resist Death",
    " of Anaesthesia",
    " of the Guardian",
    " of Inviolability",
    " of the Tortoise",
    " of the Turtle",
    " of the Armadillo",
/* 40: */
    " of the Echidna",
    " of the Armoured One",
    " of Weirdness",
    " of Pathos",
    " of Serendipity",
    " of Loss",
    " of Hedging",
    " of Indemnity",
    " of Limitation",
    " of Exclusion",
/* 50: */
    " of Repulsion",
    " of Untold Secrets",
    " of the Earth",
    " of the Turtledove",
    " of Limited Liability",
    " of Responsibility",
    " of Hadjma",
    " of Glory",
    " of Preservation",
    " of Conservation",
/* 60: */
    " of Protective Custody",
    " of the Clam",
    " of the Barnacle",
    " of the Lobster",
    " of Hairiness",
    " of Supple Strength",
    " of Space",
    " of the Vacuum",
    " of Compression",
    " of Decompression",

/* 70: */
    " of the Loofah",
    " of ",
    " of ",
    " of ",
    " of ",
    " of ",
    " of ",
    " of ",
    " of ",
    " of ",
// Sarcophagus
};

// Remember: disallow unrandart creation in abyss/pan

/*
   The following unrandart bits were taken from $pellbinder's mon-util code
   (see mon-util.h & mon-util.cc) and modified (LRH). They're in randart.cc and
   not randart.h because they're only used in this code module.
*/

#if defined(__IBMCPP__)
#define PACKED
#else
#ifndef PACKED
#define PACKED __attribute__ ((packed))
#endif
#endif

//int unranddatasize;

#ifdef __IBMCPP__
#pragma pack(push)
#pragma pack(1)
#endif

struct unrandart_entry
{
    const char *name;        // true name of unrandart (max 31 chars)
    const char *unid_name;   // un-id'd name of unrandart (max 31 chars)

    int ura_cl;        // class of ura
    int ura_ty;        // type of ura
    int ura_pl;        // plus of ura
    int ura_pl2;       // plus2 of ura
    int ura_col;       // colour of ura
    short prpty[RA_PROPERTIES];

    // special description added to 'v' command output (max 31 chars)
    const char *spec_descrip1;
    // special description added to 'v' command output (max 31 chars)
    const char *spec_descrip2;
    // special description added to 'v' command output (max 31 chars)
    const char *spec_descrip3;
};

#ifdef __IBMCPP__
#pragma pack(pop)
#endif

static struct unrandart_entry unranddata[] = {
#include "unrand.h"
};

char art_n[ITEMNAME_SIZE];
static FixedVector < bool, NO_UNRANDARTS > unrandart_exist;

static struct unrandart_entry *seekunrandart( const item_def &item );

void set_unrandart_exist(int whun, bool is_exist)
{
    unrandart_exist[whun] = is_exist;
}

bool does_unrandart_exist(int whun)
{
    return (unrandart_exist[whun]);
}

bool is_artefact( const item_def &item )
{
    return (is_random_artefact(item) || is_fixed_artefact(item));
}

// returns true is item is a pure randart or an unrandart
bool is_random_artefact( const item_def &item )
{
    return (item.flags & ISFLAG_ARTEFACT_MASK);
}

// returns true if item in an unrandart
bool is_unrandom_artefact( const item_def &item )
{
    return (item.flags & ISFLAG_UNRANDART);
}

// returns true if item is one of the origional fixed artefacts
bool is_fixed_artefact( const item_def &item )
{
    if (!is_random_artefact( item )
        && item.base_type == OBJ_WEAPONS 
        && item.special >= SPWPN_SINGING_SWORD)
    {
        return (true);
    }

    return (false);
}

int get_unique_item_status( int base_type, int art )
{
    // Note: for weapons "art" is in item.special,
    //       for orbs it's the sub_type.
    if (base_type == OBJ_WEAPONS)
    {
        if (art >= SPWPN_SINGING_SWORD && art <= SPWPN_SWORD_OF_ZONGULDROK)
            return (you.unique_items[ art - SPWPN_SINGING_SWORD ]);
        else if (art >= SPWPN_SWORD_OF_POWER && art <= SPWPN_STAFF_OF_WUCAD_MU)
            return (you.unique_items[ art - SPWPN_SWORD_OF_POWER + 24 ]);
    }
    else if (base_type == OBJ_ORBS)
    {
        if (art >= 4 && art <= 19)
            return (you.unique_items[ art + 3 ]);

    }

    return (UNIQ_NOT_EXISTS);
}

void set_unique_item_status( int base_type, int art, int status )
{
    // Note: for weapons "art" is in item.special,
    //       for orbs it's the sub_type.
    if (base_type == OBJ_WEAPONS)
    {
        if (art >= SPWPN_SINGING_SWORD && art <= SPWPN_SWORD_OF_ZONGULDROK)
            you.unique_items[ art - SPWPN_SINGING_SWORD ] = status;
        else if (art >= SPWPN_SWORD_OF_POWER && art <= SPWPN_STAFF_OF_WUCAD_MU)
            you.unique_items[ art - SPWPN_SWORD_OF_POWER + 24 ] = status;
    }
    else if (base_type == OBJ_ORBS)
    {
        if (art >= 4 && art <= 19)
            you.unique_items[ art + 3 ] = status;

    }
}

static long calc_seed( const item_def &item )
{
    return (item.special & RANDART_SEED_MASK);
}

void randart_wpn_properties( const item_def &item, 
                             randart_properties_t &proprt )
{
    ASSERT( is_random_artefact( item ) ); 

    const int aclass = item.base_type;
    const int atype  = item.sub_type;

    int i = 0;
    int power_level = 0;

    if (is_unrandom_artefact( item ))
    {
        struct unrandart_entry *unrand = seekunrandart( item );

        for (i = 0; i < RA_PROPERTIES; i++)
            proprt[i] = unrand->prpty[i];

        return;
    }

    // long seed = aclass * adam + atype * (aplus % 100) + aplus2 * 100;
    long seed = calc_seed( item );
    push_rng_state();
    seed_rng( seed );

    if (aclass == OBJ_ARMOUR)
        power_level = item.plus / 2 + 2;
    else if (aclass == OBJ_JEWELLERY)
        power_level = 1 + random2(3) + random2(2);
    else // OBJ_WEAPON
        power_level = item.plus / 3 + item.plus2 / 3;

    if (power_level < 0)
        power_level = 0;

    for (i = 0; i < RA_PROPERTIES; i++)
        proprt[i] = 0;

    if (aclass == OBJ_WEAPONS)  /* Only weapons get brands, of course */
    {
        proprt[RAP_BRAND] = SPWPN_FLAMING + random2(15);        /* brand */

        if (one_chance_in(6))
            proprt[RAP_BRAND] = SPWPN_FLAMING + random2(2);

        if (one_chance_in(6))
            proprt[RAP_BRAND] = SPWPN_ORC_SLAYING + random2(4);

        if (one_chance_in(6))
            proprt[RAP_BRAND] = SPWPN_VORPAL;

        if (proprt[RAP_BRAND] == SPWPN_FLAME
            || proprt[RAP_BRAND] == SPWPN_FROST)
        {
            proprt[RAP_BRAND] = 0;      /* missile wpns */
        }

        if (proprt[RAP_BRAND] == SPWPN_PROTECTION)
            proprt[RAP_BRAND] = 0;      /* no protection */

        if (proprt[RAP_BRAND] == SPWPN_DISRUPTION
            && !(atype == WPN_MACE || atype == WPN_GREAT_MACE
                || atype == WPN_HAMMER))
        {
            proprt[RAP_BRAND] = SPWPN_NORMAL;
        }

        // is this happens, things might get broken -- bwr
        if (proprt[RAP_BRAND] == SPWPN_SPEED && atype == WPN_QUICK_BLADE)
            proprt[RAP_BRAND] = SPWPN_NORMAL;

        if (is_range_weapon(item))
        {
            proprt[RAP_BRAND] = SPWPN_NORMAL;

            if (one_chance_in(3))
            {
                int tmp = random2(20);

                proprt[RAP_BRAND] = (tmp >= 18) ? SPWPN_SPEED :
                                    (tmp >= 14) ? SPWPN_PROTECTION :
                                    (tmp >= 10) ? SPWPN_VENOM                   
                                                : SPWPN_VORPAL + random2(3);
                if (atype == WPN_BLOWGUN
                    && (proprt[RAP_BRAND] == SPWPN_VORPAL
                        || proprt[RAP_BRAND] == SPWPN_VENOM))
                {
                    proprt[RAP_BRAND] = SPWPN_NORMAL;
                }
            }
        }


        if (is_demonic(item))
        {
            switch (random2(9))
            {
            case 0:
                proprt[RAP_BRAND] = SPWPN_DRAINING;
                break;
            case 1:
                proprt[RAP_BRAND] = SPWPN_FLAMING;
                break;
            case 2:
                proprt[RAP_BRAND] = SPWPN_FREEZING;
                break;
            case 3:
                proprt[RAP_BRAND] = SPWPN_ELECTROCUTION;
                break;
            case 4:
                proprt[RAP_BRAND] = SPWPN_VAMPIRICISM;
                break;
            case 5:
                proprt[RAP_BRAND] = SPWPN_PAIN;
                break;
            case 6:
                proprt[RAP_BRAND] = SPWPN_VENOM;
                break;
            default:
                power_level -= 2;
            }
            power_level += 2;
        }
        else if (one_chance_in(3))
            proprt[RAP_BRAND] = SPWPN_NORMAL;
        else
            power_level++;
    }

    if (one_chance_in(5))
        goto skip_mods;

    /* AC mod - not for armours or rings of protection */
    if (one_chance_in(4 + power_level)
        && aclass != OBJ_ARMOUR
        && (aclass != OBJ_JEWELLERY || atype != RING_PROTECTION))
    {
        proprt[RAP_AC] = 1 + random2(3) + random2(3) + random2(3);
        power_level++;
        if (one_chance_in(4))
        {
            proprt[RAP_AC] -= 1 + random2(3) + random2(3) + random2(3);
            power_level--;
        }
    }

    /* ev mod - not for rings of evasion */
    if (one_chance_in(4 + power_level)
        && (aclass != OBJ_JEWELLERY || atype != RING_EVASION))
    {
        proprt[RAP_EVASION] = 1 + random2(3) + random2(3) + random2(3);
        power_level++;
        if (one_chance_in(4))
        {
            proprt[RAP_EVASION] -= 1 + random2(3) + random2(3) + random2(3);
            power_level--;
        }
    }

    /* str mod - not for rings of strength */
    if (one_chance_in(4 + power_level)
        && (aclass != OBJ_JEWELLERY || atype != RING_STRENGTH))
    {
        proprt[RAP_STRENGTH] = 1 + random2(3) + random2(2);
        power_level++;
        if (one_chance_in(4))
        {
            proprt[RAP_STRENGTH] -= 1 + random2(3) + random2(3) + random2(3);
            power_level--;
        }
    }

    /* int mod - not for rings of intelligence */
    if (one_chance_in(4 + power_level)
        && (aclass != OBJ_JEWELLERY || atype != RING_INTELLIGENCE))
    {
        proprt[RAP_INTELLIGENCE] = 1 + random2(3) + random2(2);
        power_level++;
        if (one_chance_in(4))
        {
            proprt[RAP_INTELLIGENCE] -= 1 + random2(3) + random2(3) + random2(3);
            power_level--;
        }
    }

    /* dex mod - not for rings of dexterity */
    if (one_chance_in(4 + power_level)
        && (aclass != OBJ_JEWELLERY || atype != RING_DEXTERITY))
    {
        proprt[RAP_DEXTERITY] = 1 + random2(3) + random2(2);
        power_level++;
        if (one_chance_in(4))
        {
            proprt[RAP_DEXTERITY] -= 1 + random2(3) + random2(3) + random2(3);
            power_level--;
        }
    }

  skip_mods:
    if (random2(15) < power_level 
        || aclass == OBJ_WEAPONS
        || (aclass == OBJ_JEWELLERY && atype == RING_SLAYING))
    {
        goto skip_combat;
    }

    /* Weapons and rings of slaying can't get these */
    if (one_chance_in(4 + power_level))  /* to-hit */
    {
        proprt[RAP_ACCURACY] = 1 + random2(3) + random2(2);
        power_level++;
        if (one_chance_in(4))
        {
            proprt[RAP_ACCURACY] -= 1 + random2(3) + random2(3) + random2(3);
            power_level--;
        }
    }

    if (one_chance_in(4 + power_level))  /* to-dam */
    {
        proprt[RAP_DAMAGE] = 1 + random2(3) + random2(2);
        power_level++;
        if (one_chance_in(4))
        {
            proprt[RAP_DAMAGE] -= 1 + random2(3) + random2(3) + random2(3);
            power_level--;
        }
    }

  skip_combat:
    if (random2(12) < power_level)
        goto finished_powers;
    
    /* res_fire */
    if (one_chance_in(4 + power_level)
        && (aclass != OBJ_JEWELLERY
            || (atype != RING_PROTECTION_FROM_FIRE
                && atype != RING_FIRE
                && atype != RING_ICE))
        && (aclass != OBJ_ARMOUR
            || (atype != ARM_DRAGON_ARMOUR
                && atype != ARM_ICE_DRAGON_ARMOUR
                && atype != ARM_GOLD_DRAGON_ARMOUR)))
    {
        proprt[RAP_FIRE] = 1;
        if (one_chance_in(5))
            proprt[RAP_FIRE]++;
        power_level++;
    }

    /* res_cold */
    if (one_chance_in(4 + power_level)
        && (aclass != OBJ_JEWELLERY
            || (atype != RING_PROTECTION_FROM_COLD
                && atype != RING_FIRE
                && atype != RING_ICE))
        && (aclass != OBJ_ARMOUR
            || (atype != ARM_DRAGON_ARMOUR
                && atype != ARM_ICE_DRAGON_ARMOUR
                && atype != ARM_GOLD_DRAGON_ARMOUR)))
    {
        proprt[RAP_COLD] = 1;
        if (one_chance_in(5))
            proprt[RAP_COLD]++;
        power_level++;
    }

    if (random2(12) < power_level || power_level > 7)
        goto finished_powers;

    /* res_elec */
    if (one_chance_in(4 + power_level)
        && (aclass != OBJ_ARMOUR || atype != ARM_STORM_DRAGON_ARMOUR))
    {
        proprt[RAP_ELECTRICITY] = 1;
        power_level++;
    }

/* res_poison */
    if (one_chance_in(5 + power_level)
        && (aclass != OBJ_JEWELLERY || atype != RING_POISON_RESISTANCE)
        && (aclass != OBJ_ARMOUR
            || atype != ARM_GOLD_DRAGON_ARMOUR
            || atype != ARM_SWAMP_DRAGON_ARMOUR))
    {
        proprt[RAP_POISON] = 1;
        power_level++;
    }

    /* prot_life - no necromantic brands on weapons allowed */
    if (one_chance_in(4 + power_level)
        && (aclass != OBJ_JEWELLERY || atype != RING_TELEPORTATION)
        && proprt[RAP_BRAND] != SPWPN_DRAINING
        && proprt[RAP_BRAND] != SPWPN_VAMPIRICISM
        && proprt[RAP_BRAND] != SPWPN_PAIN)
    {
        proprt[RAP_NEGATIVE_ENERGY] = 1;
        power_level++;
    }

    /* res magic */
    if (one_chance_in(4 + power_level)
        && (aclass != OBJ_JEWELLERY || atype != RING_PROTECTION_FROM_MAGIC))
    {
        proprt[RAP_MAGIC] = 35 + random2(65);
        power_level++;
    }

    /* see_invis */
    if (one_chance_in(4 + power_level)
        && (aclass != OBJ_JEWELLERY || atype != RING_INVISIBILITY))
    {
        proprt[RAP_EYESIGHT] = 1;
        power_level++;
    }

    if (random2(12) < power_level || power_level > 10)
        goto finished_powers;

    /* turn invis */
    if (one_chance_in(10)
        && (aclass != OBJ_JEWELLERY || atype != RING_INVISIBILITY))
    {
        proprt[RAP_INVISIBLE] = 1;
        power_level++;
    }

    /* levitate */
    if (one_chance_in(10)
        && (aclass != OBJ_JEWELLERY || atype != RING_LEVITATION))
    {
        proprt[RAP_LEVITATE] = 1;
        power_level++;
    }

    if (one_chance_in(10))       /* blink */
    {
        proprt[RAP_BLINK] = 1;
        power_level++;
    }

    /* teleport */
    if (one_chance_in(10)
        && (aclass != OBJ_JEWELLERY || atype != RING_TELEPORTATION))
    {
        proprt[RAP_CAN_TELEPORT] = 1;
        power_level++;
    }

    /* go berserk */
    if (one_chance_in(10) && (aclass != OBJ_JEWELLERY || atype != AMU_RAGE))
    {
        proprt[RAP_BERSERK] = 1;
        power_level++;
    }

    if (one_chance_in(10))       /* sense surr */
    {
        proprt[RAP_MAPPING] = 1;
        power_level++;
    }


  finished_powers:
    /* Armours get less powers, and are also less likely to be
       cursed that wpns */
    if (aclass == OBJ_ARMOUR)
        power_level -= 4;

    if (random2(17) >= power_level || power_level < 2)
        goto finished_curses;

    switch (random2(9))
    {
    case 0:                     /* makes noise */
        if (aclass != OBJ_WEAPONS)
            break;
        proprt[RAP_NOISES] = 1 + random2(4);
        break;
    case 1:                     /* no magic */
        proprt[RAP_PREVENT_SPELLCASTING] = 1;
        break;
    case 2:                     /* random teleport */
        if (aclass != OBJ_WEAPONS)
            break;
        proprt[RAP_CAUSE_TELEPORTATION] = 5 + random2(15);
        break;
    case 3:   /* no teleport - doesn't affect some instantaneous teleports */
        if (aclass == OBJ_JEWELLERY && atype == RING_TELEPORTATION)
            break;              /* already is a ring of tport */
        if (aclass == OBJ_JEWELLERY && atype == RING_TELEPORT_CONTROL)
            break;              /* already is a ring of tport ctrl */
        proprt[RAP_BLINK] = 0;
        proprt[RAP_CAN_TELEPORT] = 0;
        proprt[RAP_PREVENT_TELEPORTATION] = 1;
        break;
    case 4:                     /* berserk on attack */
        if (aclass != OBJ_WEAPONS)
            break;
        proprt[RAP_ANGRY] = 1 + random2(8);
        break;
    case 5:                     /* susceptible to fire */
        if (aclass == OBJ_JEWELLERY
            && (atype == RING_PROTECTION_FROM_FIRE || atype == RING_FIRE
                || atype == RING_ICE))
            break;              /* already does this or something */
        if (aclass == OBJ_ARMOUR
            && (atype == ARM_DRAGON_ARMOUR || atype == ARM_ICE_DRAGON_ARMOUR
                || atype == ARM_GOLD_DRAGON_ARMOUR))
            break;
        proprt[RAP_FIRE] = -1;
        break;
    case 6:                     /* susceptible to cold */
        if (aclass == OBJ_JEWELLERY
            && (atype == RING_PROTECTION_FROM_COLD || atype == RING_FIRE
                || atype == RING_ICE))
            break;              /* already does this or something */
        if (aclass == OBJ_ARMOUR
            && (atype == ARM_DRAGON_ARMOUR || atype == ARM_ICE_DRAGON_ARMOUR
                || atype == ARM_GOLD_DRAGON_ARMOUR))
            break;
        proprt[RAP_COLD] = -1;
        break;
    case 7:                     /* speed metabolism */
        if (aclass == OBJ_JEWELLERY && atype == RING_HUNGER)
            break;              /* already is a ring of hunger */
        if (aclass == OBJ_JEWELLERY && atype == RING_SUSTENANCE)
            break;              /* already is a ring of sustenance */
        proprt[RAP_METABOLISM] = 1 + random2(3);
        break;
    case 8:   /* emits mutagenic radiation - increases magic_contamination */
        /* property is chance (1 in ...) of increasing magic_contamination */
        proprt[RAP_MUTAGENIC] = 2 + random2(4);
        break;
    }

/*
   26 - +to-hit (no wpns)
   27 - +to-dam (no wpns)
 */

finished_curses:
    if (one_chance_in(10) 
        && (aclass != OBJ_ARMOUR 
            || atype != ARM_CLOAK 
            || get_equip_race(item) != ISFLAG_ELVEN)
        && (aclass != OBJ_ARMOUR 
            || atype != ARM_BOOTS 
            || get_equip_race(item) != ISFLAG_ELVEN)
        && get_armour_ego_type( item ) != SPARM_STEALTH)
    {
        power_level++;
        proprt[RAP_STEALTH] = 10 + random2(70);

        if (one_chance_in(4))
        {
            proprt[RAP_STEALTH] = -proprt[RAP_STEALTH] - random2(20);    
            power_level--;
        }
    }

    if ((power_level < 2 && one_chance_in(5)) || one_chance_in(30))
        proprt[RAP_CURSED] = 1;

    pop_rng_state();

}

int randart_wpn_property( const item_def &item, int prop )
{
    randart_properties_t proprt;

    randart_wpn_properties( item, proprt );

    return (proprt[prop]);
}

const char *randart_name( const item_def &item )
{
    ASSERT( item.base_type == OBJ_WEAPONS );

    if (is_unrandom_artefact( item ))
    {
        const struct unrandart_entry *unrand = seekunrandart( item );
        return (item_type_known(item) ? unrand->name : unrand->unid_name);
    }

    art_n[0] = 0;

    // long seed = aclass + adam * (aplus % 100) + atype * aplus2;
    const long seed = calc_seed( item );
    push_rng_state();
    seed_rng( seed );

    if (!item_type_known(item))
    {
        switch (random2(21))
        {
        case  0: strcat(art_n, "brightly glowing "); break;
        case  1: strcat(art_n, "runed "); break;
        case  2: strcat(art_n, "smoking "); break;
        case  3: strcat(art_n, "bloodstained "); break;
        case  4: strcat(art_n, "twisted "); break;
        case  5: strcat(art_n, "shimmering "); break;
        case  6: strcat(art_n, "warped "); break;
        case  7: strcat(art_n, "crystal "); break;
        case  8: strcat(art_n, "jewelled "); break;
        case  9: strcat(art_n, "transparent "); break;
        case 10: strcat(art_n, "encrusted "); break;
        case 11: strcat(art_n, "pitted "); break;
        case 12: strcat(art_n, "slimy "); break;
        case 13: strcat(art_n, "polished "); break;
        case 14: strcat(art_n, "fine "); break;
        case 15: strcat(art_n, "crude "); break;
        case 16: strcat(art_n, "ancient "); break;
        case 17: strcat(art_n, "ichor-stained "); break;
        case 18: strcat(art_n, "faintly glowing "); break;
        case 19: strcat(art_n, "steaming "); break;
        case 20: strcat(art_n, "shiny "); break;
        }

        strcat(art_n, item_base_name(item).c_str());
        pop_rng_state();
        return (art_n);
    }

    if (coinflip())
    {
        strcat(art_n, item_base_name(item).c_str());
        strcat(art_n, rand_wpn_names[random2(390)]);
    }
    else
    {
        char st_p[ITEMNAME_SIZE];

        make_name(random_int(), false, st_p);
        strcat(art_n, item_base_name(item).c_str());

        if (one_chance_in(3))
        {
            strcat(art_n, " of ");
            strcat(art_n, st_p);
        }
        else
        {
            strcat(art_n, " \"");
            strcat(art_n, st_p);
            strcat(art_n, "\"");
        }
    }

    pop_rng_state();

    return (art_n);
}

const char *randart_armour_name( const item_def &item )
{
    ASSERT( item.base_type == OBJ_ARMOUR );

    if (is_unrandom_artefact( item ))
    {
        const struct unrandart_entry *unrand = seekunrandart( item );
        return (item_type_known(item) ? unrand->name : unrand->unid_name);
    }

    art_n[0] = 0;

    // long seed = aclass + adam * (aplus % 100) + atype * aplus2;
    const long seed = calc_seed( item );
    
    push_rng_state();
    seed_rng( seed );

    if (!item_type_known(item))
    {
        switch (random2(21))
        {
        case  0: strcat(art_n, "brightly glowing "); break;
        case  1: strcat(art_n, "runed "); break;
        case  2: strcat(art_n, "smoking "); break;
        case  3: strcat(art_n, "bloodstained "); break;
        case  4: strcat(art_n, "twisted "); break;
        case  5: strcat(art_n, "shimmering "); break;
        case  6: strcat(art_n, "warped "); break;
        case  7: strcat(art_n, "heavily runed "); break;
        case  8: strcat(art_n, "jeweled "); break;
        case  9: strcat(art_n, "transparent "); break;
        case 10: strcat(art_n, "encrusted "); break;
        case 11: strcat(art_n, "pitted "); break;
        case 12: strcat(art_n, "slimy "); break;
        case 13: strcat(art_n, "polished "); break;
        case 14: strcat(art_n, "fine "); break;
        case 15: strcat(art_n, "crude "); break;
        case 16: strcat(art_n, "ancient "); break;
        case 17: strcat(art_n, "ichor-stained "); break;
        case 18: strcat(art_n, "faintly glowing "); break;
        case 19: strcat(art_n, "steaming "); break;
        case 20: strcat(art_n, "shiny "); break;
        }
        strcat(art_n, item_base_name(item).c_str());
        pop_rng_state();
        return (art_n);
    }

    if (coinflip())
    {
        strcat(art_n, item_base_name(item).c_str());
        strcat(art_n, rand_armour_names[random2(71)]);
    }
    else
    {
        char st_p[ITEMNAME_SIZE];

        make_name(random_int(), false, st_p);
        strcat(art_n, item_base_name(item).c_str());
        if (one_chance_in(3))
        {
            strcat(art_n, " of ");
            strcat(art_n, st_p);
        }
        else
        {
            strcat(art_n, " \"");
            strcat(art_n, st_p);
            strcat(art_n, "\"");
        }
    }

    pop_rng_state();

    return (art_n);
}

const char *randart_ring_name( const item_def &item )
{
    ASSERT( item.base_type == OBJ_JEWELLERY );

    int temp_rand = 0;          // probability determination {dlb}

    if (is_unrandom_artefact( item ))
    {
        struct unrandart_entry *unrand = seekunrandart( item );

        return (item_type_known(item) ? unrand->name
                                      : unrand->unid_name);
    }

    char st_p[ITEMNAME_SIZE];

    art_n[0] = 0;

    // long seed = aclass + adam * (aplus % 100) + atype * aplus2;
    const long seed = calc_seed( item );
    push_rng_state();
    seed_rng( seed );

    if (!item_type_known(item))
    {
        temp_rand = random2(21);

        strcat(art_n,  (temp_rand == 0)  ? "brightly glowing" :
                       (temp_rand == 1)  ? "runed" :
                       (temp_rand == 2)  ? "smoking" :
                       (temp_rand == 3)  ? "ruby" :
                       (temp_rand == 4)  ? "twisted" :
                       (temp_rand == 5)  ? "shimmering" :
                       (temp_rand == 6)  ? "warped" :
                       (temp_rand == 7)  ? "crystal" :
                       (temp_rand == 8)  ? "diamond" :
                       (temp_rand == 9)  ? "transparent" :
                       (temp_rand == 10) ? "encrusted" :
                       (temp_rand == 11) ? "pitted" :
                       (temp_rand == 12) ? "slimy" :
                       (temp_rand == 13) ? "polished" :
                       (temp_rand == 14) ? "fine" :
                       (temp_rand == 15) ? "crude" :
                       (temp_rand == 16) ? "ancient" :
                       (temp_rand == 17) ? "emerald" :
                       (temp_rand == 18) ? "faintly glowing" :
                       (temp_rand == 19) ? "steaming"
                                         : "shiny");

        strcat(art_n, " ");
        strcat(art_n, (item.sub_type < AMU_RAGE) ? "ring" : "amulet");

        pop_rng_state();

        return (art_n);
    }

    if (one_chance_in(5))
    {
        strcat(art_n, (item.sub_type < AMU_RAGE) ? "ring" : "amulet");
        strcat(art_n, rand_armour_names[random2(71)]);
    }
    else
    {
        make_name(random_int(), false, st_p);

        strcat(art_n, (item.sub_type < AMU_RAGE) ? "ring" : "amulet");

        if (one_chance_in(3))
        {
            strcat(art_n, " of ");
            strcat(art_n, st_p);
        }
        else
        {
            strcat(art_n, " \"");
            strcat(art_n, st_p);
            strcat(art_n, "\"");
        }
    }

    pop_rng_state();

    return (art_n);
}                               // end randart_ring_name()

static struct unrandart_entry *seekunrandart( const item_def &item )
{
    int x = 0;

    while (x < NO_UNRANDARTS)
    {
        if (unranddata[x].ura_cl == item.base_type 
            && unranddata[x].ura_ty == item.sub_type
            && unranddata[x].ura_pl == item.plus 
            && unranddata[x].ura_pl2 == item.plus2)
        {
            return (&unranddata[x]);
        }

        x++;
    }

    return (&unranddata[0]);  // Dummy object
}                               // end seekunrandart()

int find_unrandart_index(int item_number)
{
    int x;

    for(x=0; x < NO_UNRANDARTS; x++)
    {
        if (unranddata[x].ura_cl == mitm[item_number].base_type
            && unranddata[x].ura_ty == mitm[item_number].sub_type
            && unranddata[x].ura_pl == mitm[item_number].plus
            && unranddata[x].ura_pl2 == mitm[item_number].plus2)
        {
            return (x);
        }
    }

    return (-1);
}

int find_okay_unrandart(unsigned char aclass, unsigned char atype)
{
    int x, count;
    int ret = -1;

    for (x = 0, count = 0; x < NO_UNRANDARTS; x++)
    {
        if (unranddata[x].ura_cl == aclass 
            && !does_unrandart_exist(x)
            && (atype == OBJ_RANDOM || unranddata[x].ura_ty == atype))
        {
            count++;

            if (one_chance_in(count))
                ret = x;
        }
    }

    return (ret);
}                               // end find_okay_unrandart()

// which == 0 (default) gives random fixed artefact.
// Returns true if successful.
bool make_item_fixed_artefact( item_def &item, bool in_abyss, int which )
{
    bool  force = true;  // we force any one asked for specifically

    if (!which)
    {
        // using old behaviour... try only once. -- bwr
        force = false;  

        which = SPWPN_SINGING_SWORD + random2(12);
        if (which >= SPWPN_SWORD_OF_CEREBOV)
            which += 3; // skip over Cerebov's, Dispater's, and Asmodeus' weapons
    }

    int status = get_unique_item_status( OBJ_WEAPONS, which );

    if ((status == UNIQ_EXISTS 
            || (in_abyss && status == UNIQ_NOT_EXISTS)
            || (!in_abyss && status == UNIQ_LOST_IN_ABYSS))
        && !force)
    {
        return (false);
    }

    switch (which)
    {
    case SPWPN_SINGING_SWORD:
        item.base_type = OBJ_WEAPONS;
        item.sub_type = WPN_LONG_SWORD;
        item.plus  = 7;
        item.plus2 = 6;
        break;

    case SPWPN_WRATH_OF_TROG:
        item.base_type = OBJ_WEAPONS;
        item.sub_type = WPN_BATTLEAXE;
        item.plus  = 3;
        item.plus2 = 11;
        break;

    case SPWPN_SCYTHE_OF_CURSES:
        item.base_type = OBJ_WEAPONS;
        item.sub_type = WPN_SCYTHE;
        item.plus  = 13;
        item.plus2 = 13;
        break;

    case SPWPN_MACE_OF_VARIABILITY:
        item.base_type = OBJ_WEAPONS;
        item.sub_type = WPN_MACE;
        item.plus  = random2(16) - 4;
        item.plus2 = random2(16) - 4;
        break;

    case SPWPN_GLAIVE_OF_PRUNE:
        item.base_type = OBJ_WEAPONS;
        item.sub_type = WPN_GLAIVE;
        item.plus  = 0;
        item.plus2 = 12;
        break;

    case SPWPN_SCEPTRE_OF_TORMENT:
        item.base_type = OBJ_WEAPONS;
        item.sub_type = WPN_MACE;
        item.plus  = 7;
        item.plus2 = 6;
        break;

    case SPWPN_SWORD_OF_ZONGULDROK:
        item.base_type = OBJ_WEAPONS;
        item.sub_type = WPN_LONG_SWORD;
        item.plus  = 9;
        item.plus2 = 9;
        break;

    case SPWPN_SWORD_OF_POWER:
        item.base_type = OBJ_WEAPONS;
        item.sub_type = WPN_GREAT_SWORD;
        item.plus  = 0; // set on wield
        item.plus2 = 0; // set on wield
        break;

    case SPWPN_KNIFE_OF_ACCURACY:
        item.base_type = OBJ_WEAPONS;
        item.sub_type = WPN_DAGGER;
        item.plus  = 27;
        item.plus2 = -1;
        break;

    case SPWPN_STAFF_OF_OLGREB:
        item.base_type = OBJ_WEAPONS;
        item.sub_type = WPN_QUARTERSTAFF;
        item.plus  = 0; // set on wield
        item.plus2 = 0; // set on wield
        break;

    case SPWPN_VAMPIRES_TOOTH:
        item.base_type = OBJ_WEAPONS;
        item.sub_type = WPN_DAGGER;
        item.plus  = 3;
        item.plus2 = 4;
        break;

    case SPWPN_STAFF_OF_WUCAD_MU:
        item.base_type = OBJ_WEAPONS;
        item.sub_type = WPN_QUARTERSTAFF;
        item.plus  = 0; // set on wield
        item.plus2 = 0; // set on wield
        break;

    case SPWPN_SWORD_OF_CEREBOV:
        item.base_type = OBJ_WEAPONS;
        item.sub_type = WPN_GREAT_SWORD;
        item.plus  = 6;
        item.plus2 = 6;
        item.colour = YELLOW;
        do_curse_item( item );
        break;

    case SPWPN_STAFF_OF_DISPATER:
        item.base_type = OBJ_WEAPONS;
        item.sub_type = WPN_QUARTERSTAFF;
        item.plus  = 4;
        item.plus2 = 4;
        item.colour = YELLOW;
        break;

    case SPWPN_SCEPTRE_OF_ASMODEUS:
        item.base_type = OBJ_WEAPONS;
        item.sub_type = WPN_QUARTERSTAFF;
        item.plus  = 7;
        item.plus2 = 7;
        item.colour = RED;
        break;

    default:
        DEBUGSTR( "Trying to create illegal fixed artefact!" );
        return (false);
    }

    // If we get here, we've made the artefact
    item.special = which;
    item.quantity = 1;

    // Items originally generated in the abyss and not found will be 
    // shifted to "lost in abyss", and will only be found there. -- bwr
    set_unique_item_status( OBJ_WEAPONS, which, UNIQ_EXISTS );

    return (true);
}

bool make_item_randart( item_def &item )
{
    if (item.base_type != OBJ_WEAPONS 
        && item.base_type != OBJ_ARMOUR
        && item.base_type != OBJ_JEWELLERY)
    {
        return (false);
    }

    item.flags |= ISFLAG_RANDART;
    item.special = (random_int() & RANDART_SEED_MASK);

    return (true);
}

// void make_item_unrandart( int x, int ura_item )
bool make_item_unrandart( item_def &item, int unrand_index )
{
    item.base_type = unranddata[unrand_index].ura_cl;
    item.sub_type  = unranddata[unrand_index].ura_ty;
    item.plus      = unranddata[unrand_index].ura_pl;
    item.plus2     = unranddata[unrand_index].ura_pl2;
    item.colour    = unranddata[unrand_index].ura_col;

    item.flags |= ISFLAG_UNRANDART; 
    item.special = unranddata[ unrand_index ].prpty[ RAP_BRAND ];

    if (unranddata[ unrand_index ].prpty[ RAP_CURSED ])
        do_curse_item( item );

    set_unrandart_exist( unrand_index, 1 );

    return (true);
}                               // end make_item_unrandart()

const char *unrandart_descrip( char which_descrip, const item_def &item )
{
/* Eventually it would be great to have randomly generated descriptions for
   randarts. */
    struct unrandart_entry *unrand = seekunrandart( item );

    return ((which_descrip == 0) ? unrand->spec_descrip1 :
            (which_descrip == 1) ? unrand->spec_descrip2 :
            (which_descrip == 2) ? unrand->spec_descrip3 : "Unknown.");

}                               // end unrandart_descrip()
