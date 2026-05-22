MODULE 6 — POSITION SIZING & RISK MANAGEMENT ENGINE

This module converts the validated trade opportunities from MODULE 4
and the execution plan from MODULE 5 into real position sizing decisions.

MODULE 6 does NOT generate new trades.

MODULE 6 determines:

position size
risk exposure
portfolio diversification
maximum capital at risk
trade management rules

--------------------------------------------------

STEP 24 — TOTAL CAPITAL INPUT

Ask the user to specify total trading capital.

Example:

Total Trading Capital: $10,000

This value will be used to calculate all risk allocations.

--------------------------------------------------

STEP 25 — MAXIMUM RISK PER TRADE

Define the maximum acceptable loss per trade.

Standard professional rules:

Conservative: 0.5% – 1% per trade  
Moderate: 1% – 2% per trade  
Aggressive: 2% – 3% per trade

Default rule:

Maximum risk per trade = 1% of total capital

Example:

Account size: $10,000  
Max risk per trade (1%) = $100

This means if stop loss is hit, loss must not exceed $100.



STEP 26 — POSITION SIZE CALCULATION

Calculate position size based on:

entry price
stop loss distance
maximum risk allowed

Formula:

Position Size = Maximum Risk ÷ Stop Loss Distance

Example:

Entry: EURUSD 1.0800  
Stop Loss: 1.0850  
Stop distance: 50 pips

Max risk: $100

Position size = adjusted so 50 pips loss = $100.

Return suggested lot size or contract size.

--------------------------------------------------
--------------------------------------------------

STEP 26A — MARKET OPTIONALITY & FLEXIBILITY ENGINE

Purpose:
Analyze whether positioning, exposure, leverage, execution decisions, and portfolio structure preserve strategic flexibility and future optionality under uncertain market conditions.

Markets are probabilistic systems.

Overcommitment reduces adaptability and increases fragility.

--------------------------------------------------

A. OPTIONALITY ANALYSIS

Evaluate whether current positioning preserves:

- flexibility
- adaptability
- defensive maneuverability
- future opportunity access
- liquidity availability
- risk control capacity
- repositioning ability

--------------------------------------------------

B. OVERCOMMITMENT DETECTION

Detect whether exposure appears:

- excessively concentrated
- emotionally overcommitted
- leverage dependent
- inflexible
- overly directional
- vulnerable to narrative reversal
- vulnerable to liquidity instability

--------------------------------------------------

C. FLEXIBILITY STRUCTURE ANALYSIS

Determine whether trader/system behavior reflects:

- adaptive thinking
- rigid assumptions
- probabilistic flexibility
- defensive preparation
- strategic patience
- emotional attachment to narratives
- excessive certainty bias

--------------------------------------------------

D. OPTIONALITY STABILITY CLASSIFICATION

Classify positioning flexibility as:

HIGH FLEXIBILITY
MODERATE FLEXIBILITY
LIMITED FLEXIBILITY
RIGID POSITIONING
DANGEROUS OVERCOMMITMENT

Dangerous overcommitment increases fragility risk.

--------------------------------------------------

E. SURVIVAL & ADAPTABILITY ANALYSIS

Evaluate whether the system can:

- survive volatility expansion
- adapt to regime change
- rotate narratives
- reposition efficiently
- absorb execution failure
- withstand uncertainty
- preserve future capital deployment

--------------------------------------------------

F. OPTIONALITY PROBABILITY ENGINE

Estimate probability that optionality conditions may lead to:

- long-term survivability
- defensive stability
- adaptive repositioning
- emotional overcommitment risk
- leverage instability
- execution fragility
- asymmetric opportunity preservation

Use probability language only.

--------------------------------------------------

G. EXECUTION IMPLICATIONS

If optionality is strong:

- survivability improves
- adaptability improves
- emotional stability improves
- strategic patience improves

If positioning becomes rigid or overcommitted:

- fragility risk increases
- emotional decision risk increases
- leverage instability risk increases
- execution flexibility decreases

--------------------------------------------------

IMPORTANT RULES

1. Flexibility is a major survival advantage in probabilistic systems.

2. Overcommitment reduces adaptability.

3. Preserving future optionality improves long-term expectancy.

4. Emotional attachment increases rigidity risk.

5. Strategic patience often creates asymmetric advantage.

6. Survival and adaptability matter more than short-term certainty.

--------------------------------------------------

STEP 27 — CONVICTION-BASED POSITION ADJUSTMENT

Adjust position size based on Trade Conviction Score from MODULE 4.

Conviction Score 90–100
→ Full position size

Conviction Score 75–89
→ Standard position size

Conviction Score 60–74
→ Half position size

Conviction Score <60
→ WATCHLIST
→ No position opened

--------------------------------------------------

STEP 28 — PORTFOLIO RISK LIMIT

Ensure total portfolio exposure remains controlled.

Rules:

Maximum simultaneous trades: 5

Maximum total capital at risk across all trades: 5% of portfolio.

Example:

$10,000 account  
Maximum portfolio risk = $500

If new trade exceeds this limit,
reduce position size or reject the trade.

--------------------------------------------------

STEP 29 — CORRELATED TRADE CHECK

Detect correlated trades that increase hidden risk.

Examples:

EURUSD short
GBPUSD short
AUDUSD short

All represent **USD long exposure**.

If multiple trades share the same macro exposure:

Reduce position sizes.

CORRELATION CASCADE RISK

Correlated trades may create hidden portfolio concentration.

Examples:

- multiple USD longs
- multiple tech longs
- multiple risk-on crypto trades
- multiple bond-duration trades

During volatility shocks:

correlated positions may fail simultaneously.

The system should evaluate:

- hidden macro overlap
- liquidity overlap
- narrative overlap
- directional concentration

High correlation environments require:

- reduced exposure
- defensive sizing
- tighter portfolio controls

DOUBLE ENTRY EXECUTION RULE

Multiple entries on the same instrument are only allowed if:

- entries represent different execution structures
- entries represent different probabilistic pathways
- total combined risk remains within maximum trade risk
- macro conditions remain aligned
- volatility conditions remain acceptable

Examples of approved dual-entry structures:

- pullback entry + breakout confirmation
- short-term TP + runner position
- higher timeframe entry + lower timeframe continuation

Duplicate entries with identical structure, timing, and directional exposure should be avoided because they create correlated execution risk.
--------------------------------------------------

STEP 30 — TRADE MANAGEMENT PLAN

Define how the trade will be managed after entry.

Possible management methods:

partial profit taking
trailing stop
break-even stop
time-based exit

Example:

Take Profit 1: close 50% of position  
Take Profit 2: trail stop loss

--------------------------------------------------

STEP 30A — WINNER EXPANSION & TIMEFRAME SCALING ENGINE

Purpose:
Manage profitable trades so that small initial risk can potentially capture large non-random market moves.

The system must not focus only on perfect entries.

The system must also determine how to let rare strong winners expand while controlling downside risk.

--------------------------------------------------

A. INITIAL RISK PHASE

Enter trade with predefined stop loss and controlled risk.

If trade moves against the position:
- accept small controlled loss
- do not widen stop emotionally

--------------------------------------------------

B. BREAK-EVEN TRANSITION

If price moves favorably by approximately 1R:

- consider moving stop loss to break-even
- reduce downside exposure
- protect capital
- avoid emotional interference

--------------------------------------------------

C. TIMEFRAME SCALING RULE

If trade continues moving favorably:

scale management from lower timeframe to higher timeframe.

Example:

M1 entry
→ M5 management
→ M15 management
→ H1 management
→ H4 management
→ Daily management

The stronger the trade becomes, the more room it should be given.

--------------------------------------------------

D. TRAILING STOP EXPANSION

As timeframe increases, trailing distance may widen using:

- ATR
- swing structure
- volatility range
- higher timeframe invalidation
- discretionary structure

Do NOT use fixed tiny trailing stops on large winning trades.

--------------------------------------------------

E. BIG WINNER CAPTURE LOGIC

The system should recognize that most trades may produce:

- small losses
- break-even outcomes
- small wins

But rare strong trades may produce large returns.

The objective is to survive the small failures and stay available for the rare large winners.

--------------------------------------------------

F. PROFIT TARGET WARNING

Fixed take-profit targets may close trades too early during rare strong trends.

Use fixed TP only when:

- trade is short-term
- market is choppy
- objective is fast execution
- volatility is unstable
- challenge/rule requirement demands simplicity

For strong trending environments, trailing management may be superior.

--------------------------------------------------

G. PROBABILITY RULE

Most trades will not become big winners.

The system must accept this.

Do not force every trade to become a large trend trade.

Only scale up timeframe when market proves strength.

--------------------------------------------------

IMPORTANT RULES

1. Entry is not the full edge.

2. Trade management can create the edge.

3. Small controlled losses are acceptable.

4. Rare large winners must not be cut too early.

5. Timeframe scaling allows winners to escape short-term noise.

6. The system must protect downside while leaving upside open.

7. Do not confuse random short-term noise with real trend continuation.

--------------------------------------------------
--------------------------------------------------

STEP 31 — RISK SUMMARY OUTPUT

Return final trading plan.

For each approved trade display:

Instrument
Direction
Entry price
Stop loss
Target
Position size
Maximum risk
Conviction score
Execution status

Execution status:

APPROVED
REDUCED SIZE
WATCHLIST
REJECTED

--------------------------------------------------

FINAL OUTPUT

Provide portfolio risk summary:

Total trades approved
Total capital at risk
Remaining risk capacity
Exposure by asset class
Exposure by macro theme