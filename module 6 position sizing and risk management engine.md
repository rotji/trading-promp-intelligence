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