# Lists of Live Data Sources

This file collects practical sources and tools for live macro, funding, order-flow, and execution data.

## How to use this file

1. Start with the data categories that are easiest for you to access.
2. Match your available tools to the required source types.
3. Use the lists as a checklist for building a live scan routine.
4. For each trade, verify macro, funding, and order-flow context before taking action.
5. Update this file over time as you add new feeds or platforms.

## 1. Macro data
Use these for real-time economic and policy context.

- Central bank websites / releases
  - Federal Reserve (Fed)
  - European Central Bank (ECB)
  - Bank of Japan (BOJ)
  - Bank of England (BOE)
  - Swiss National Bank (SNB)
  - Reserve Bank of Australia (RBA)
  - People’s Bank of China (PBOC)
- Economic calendars
  - ForexFactory
  - DailyFX
  - Investing.com
  - Econoday
  - Bloomberg Economic Calendar
- Public macro APIs
  - FRED API
  - TradingEconomics API
  - AlphaVantage
  - Quandl / Nasdaq Data Link
  - Twelve Data
- News providers
  - Reuters
  - Bloomberg
  - Financial Times
  - CNBC

## 2. Funding / liquidity data
Use these for repo, swap, dollar funding, credit, and liquidity stress.

- Fed / FRED
  - H.15 rates
  - SOFR
  - reverse repo / overnight repo
  - Fed balance sheet
- CME / ICE
  - Fed Funds futures
  - SOFR futures
  - Eurodollar curve
  - swap spreads
- BIS
  - FX swap turnover
  - global liquidity and funding reports
- Bank liquidity indicators
  - LIBOR/OIS spreads
  - Euribor-OIS spreads
  - CDS curves
  - Treasury repo rates
- Specialized data services
  - Bloomberg (swap spreads, repo, funding curves)
  - Refinitiv / LSEG
  - S&P Global Market Intelligence
  - IHS Markit

## 3. Order flow / execution verification
For real order-flow and liquidity confirmation.

- DOM / order-book tools
  - Bookmap
  - Jigsaw Trading
  - Sierra Chart
  - NinjaTrader
  - ATAS
  - Quantower
- Broker feeds with real volume/tick data
  - LMAX
  - FXCM
  - OANDA
  - Dukascopy
  - Saxo
  - Interactive Brokers (for futures/tick)
- Futures and options flow
  - COT reports (CFTC)
  - CME open interest
  - CME FX futures volume
  - options flow systems (e.g. SqueezeMetrics, OptionStrat, FlowAlgo)
- Tick-volume proxies
  - TradingView volume ticks
  - MT4/MT5 tick charts
  - broker-provided tick count
- Liquidity depth
  - Level 2 / DOM for futures or FX instruments
  - depth-of-market tools available in advanced platforms

## 3B. Institutional-grade real-time systems
For professional-level market infrastructure and data.

- Terminal platforms
  - Bloomberg Terminal (comprehensive macro, funding, positioning, news)
  - Refinitiv Eikon / Refinitiv Desktop (alternative to Bloomberg)
  - ICE Data (fixed income, derivatives, FX swap data)
  - CME Direct (direct futures and options data)
- Data aggregation platforms
  - CQG (charting, order flow, market depth)
  - dxFeed (real-time market data API and feeds)
  - Polygon (multi-asset real-time data API)
- Advanced order-flow and positioning feeds
  - Institutional options flow feeds (e.g., Unusual Whales, FlowAlgo, OptionStrat professional tier)
  - Prime broker feeds (proprietary bank-level positioning and funding data)
  - Swap dealer feeds (direct dealer positioning and inventory data)
  - Cross-bank liquidity feeds (aggregated interbank order-flow data)
- Specialized liquidity intelligence
  - BIS high-frequency FX swap and cross-border flow data
  - Dealer inventory and positioning services
  - Counterparty and contagion risk feeds

## 4. FX-specific structural flow / positioning
For FX equilibrium, relative strength, carry, and dealer context.

- BIS FX swap and funding reports
- CFTC FX futures positioning
- FX swap curves and cross-currency basis
- Carry trade indicators
  - yield differentials
  - swap points
  - funding cost curves
- Positioning data
  - COT
  - FX futures open interest
  - options delta/gamma exposure if available

## 5. Chart and footprint intelligence
For the chart footprints the prompt mentions.

- TradingView
- MT4 / MT5
- NinjaTrader
- Sierra Chart
- Bookmap / ATAS for footprint and liquidity sweep detection
- Volume profile / market-profile tools

## 6. Practical setup for pre-London routine
If you want a real “before London open” routine:
- Macro: check economic calendar + recent central bank signals
- Funding: inspect repo, swap spreads, dollar liquidity, SOFR
- Order flow: confirm via broker DOM or futures flow
- Chart: compare higher timeframes + current session structure
- Risk: verify news and volatility conditions before entry
- Governance: confirm the master execution authorization and survivability status from `module 0 All system rules and market classification framework` before committing
- Session readiness: during London/New York session and overlap, ensure session authorization and governance alignment are both confirmed before execution

## 7. Key point
The attached document is a workflow specification, not itself an automatic data source.

To make it work you need to connect it with:
- live macro feeds
- funding/liquidity feeds
- broker order-flow tools
- execution/chart platforms

## 8. Suggested real source categories

### Real-time macro sources
- Central bank releases
- Economic calendar feeds
- Real-time macro APIs
- Financial news services

### Real-time funding sources
- Repo and funding rate data
- Swap spreads and swap curves
- Dollar liquidity indicators
- CDS and credit spread data

### Real-time order flow sources
- DOM / order-book feeds
- Tick and volume feeds
- Futures / options positioning feeds
- Broker execution data

### Real-time structural data sources
- BIS liquidity / FX swap reports
- COT / futures positioning
- Options gamma / positioning systems
- Macro and funding overlays

## 9. Recommended steps to implement the prompt
1. Identify the tools you can access immediately.
2. Choose a chart platform with good session and volume tools.
3. Connect a macro calendar or API for news and policy data.
4. Add a funding data source for repo, swap, and dollar stress.
5. Add order-flow or tick-volume verification if available.
6. Use the list above as your daily scan checklist.

---

This file is intentionally designed to be stored separately from `PART TWO.MD` as a practical reference list.

If you want to track deals like the Nigeria–UAE $5B swap at an institutional/macroeconomic level, you need to build a **multi-layer intelligence stack** — not rely on one news source.

The real information is fragmented across:

* government documents,
* IMF reports,
* debt market terminals,
* central bank releases,
* bond pricing,
* geopolitics,
* commodity flows,
* and institutional research.

Below is the actual “rabbit hole map” professionals use.

---

# TIER 1 — PRIMARY SOURCES (MOST IMPORTANT)

These are the closest things to “ground truth.”

---

## 1. [IMF Nigeria Page](https://www.imf.org/en/Countries/NGA?utm_source=chatgpt.com)

This is critical.

Track:

* Article IV consultations,
* debt sustainability analysis,
* reserve warnings,
* FX policy,
* fiscal risks,
* banking stress,
* sovereign vulnerability.

For Nigeria specifically:

* IMF often reveals risks before markets fully price them. ([IMF][1])

---

## 2. [Central Bank of Nigeria (CBN)](https://www.cbn.gov.ng?utm_source=chatgpt.com)

Track:

* FX reserves,
* monetary policy,
* exchange rates,
* inflation,
* liquidity operations,
* banking system stress,
* external reserves.

Most people underestimate how important central banks are.

---

## 3. [Nigeria Debt Management Office (DMO)](https://www.dmo.gov.ng?utm_source=chatgpt.com)

Extremely important.

This is where sovereign debt architecture becomes visible.

Track:

* debt issuance,
* Eurobonds,
* external borrowing,
* debt maturity schedules,
* debt servicing,
* domestic bond auctions.

This directly connects to:

* refinancing risk,
* rollover risk,
* sovereign stress probability.

---

## 4. [Nigeria Ministry of Finance](https://www.finance.gov.ng?utm_source=chatgpt.com)

Track:

* budget deficits,
* borrowing plans,
* sovereign partnerships,
* fiscal policy,
* infrastructure financing.

---

# TIER 2 — GLOBAL MACRO & FINANCIAL NEWS

These are your real-time institutional intelligence feeds.

---

## 5. [Reuters](https://www.reuters.com/world/africa/?utm_source=chatgpt.com)

One of the best sources globally.

Reuters is crucial because:

* institutional traders read it,
* sovereign desks read it,
* hedge funds read it,
* central banks monitor it.

The IMF warning about the swap came through Reuters. ([Reuters][2])

Track Reuters for:

* sovereign debt,
* sanctions,
* commodity shocks,
* central bank policy,
* Gulf capital flows,
* emerging market liquidity.

---

## 6. [Bloomberg](https://www.bloomberg.com/africa?utm_source=chatgpt.com)

This is elite-level macro intelligence.

Bloomberg tracks:

* sovereign bonds,
* capital flows,
* swap structures,
* liquidity stress,
* hedge fund positioning,
* yield curves.

Professionals practically live inside Bloomberg terminals.

---

## 7. [Financial Times](https://www.ft.com/africa?utm_source=chatgpt.com)

Best for:

* geopolitical finance,
* sovereign debt analysis,
* Gulf/Africa financing,
* structural macro analysis.

---

# TIER 3 — LIVE MARKET TRACKING

This is where you stop reading news
and start reading the financial nervous system directly.

---

# FX MARKETS

## 8. [TradingView](https://www.tradingview.com?utm_source=chatgpt.com)

You already mentioned this.

Track:

* USDNGN,
* DXY (Dollar Index),
* Brent crude,
* US10Y yields,
* Gold,
* Emerging market currencies.

This becomes your real-time macro dashboard.

---

# KEY ASSETS TO WATCH

## Dollar Liquidity

* DXY
* US10Y
* SOFR
* Fed Funds Rate

## Nigeria Stress

* USDNGN
* Nigeria Eurobond yields
* Foreign reserves

## Oil Dependency

* Brent Crude Oil
* WTI crude

## Risk Appetite

* VIX volatility index
* Emerging market bond spreads

---

# TIER 4 — SOVEREIGN DEBT & BOND INTELLIGENCE

This is where the advanced rabbit hole starts.

---

## 9. [World Government Bonds](https://www.worldgovernmentbonds.com?utm_source=chatgpt.com)

Track:

* Nigeria bond yields,
* yield spreads,
* debt stress,
* CDS proxies,
* emerging market comparisons.

If Nigeria bond yields spike:
markets are pricing higher sovereign risk.

---

## 10. [Fitch Ratings](https://www.fitchratings.com?utm_source=chatgpt.com)

## 11. [Moody’s](https://www.moodys.com?utm_source=chatgpt.com)

## 12. [S&P Global Ratings](https://www.spglobal.com/ratings?utm_source=chatgpt.com)

These agencies:

* monitor sovereign credit quality,
* detect debt fragility,
* analyze refinancing risk.

When ratings downgrade:
capital becomes more expensive.

---

# TIER 5 — GLOBAL CAPITAL FLOW TRACKING

This is the deep institutional layer.

---

## 13. [BIS (Bank for International Settlements)](https://www.bis.org?utm_source=chatgpt.com)

One of the most important institutions on Earth for macro analysis.

Tracks:

* global dollar liquidity,
* cross-border banking flows,
* derivatives,
* sovereign exposure,
* shadow banking.

The BIS is basically a window into the global financial plumbing.

---

## 14. [World Bank Data](https://data.worldbank.org?utm_source=chatgpt.com)

Track:

* external debt,
* reserves,
* GDP,
* trade balances,
* poverty,
* infrastructure financing.

---

# TIER 6 — COMMODITY & ENERGY INTELLIGENCE

Nigeria’s macro system is highly oil-sensitive.

---

## 15. [OPEC](https://www.opec.org?utm_source=chatgpt.com)

Track:

* oil production quotas,
* supply shocks,
* geopolitical energy risks.

---

## 16. [EIA (U.S. Energy Information Administration)](https://www.eia.gov?utm_source=chatgpt.com)

Track:

* crude inventories,
* oil demand,
* global energy forecasts.

Oil drives:

* Nigeria FX inflows,
* reserves,
* fiscal stability.

---

# TIER 7 — GEOPOLITICAL CAPITAL FLOWS

The UAE deal is also geopolitical.

---

## 17. [Middle East Institute](https://www.mei.edu?utm_source=chatgpt.com)

Track:

* Gulf–Africa investment expansion,
* sovereign wealth strategy,
* UAE/Africa relations.

---

## 18. [Chatham House](https://www.chathamhouse.org?utm_source=chatgpt.com)

High-level geopolitical + macro research.

---

# REAL-TIME MONITORING STACK YOU SHOULD BUILD

Your future macro system should eventually monitor:

| Layer            | What To Track                            |
| ---------------- | ---------------------------------------- |
| Sovereign Risk   | Debt/GDP, deficits, refinancing          |
| FX Stress        | USDNGN, reserves, black-market spread    |
| Dollar Liquidity | DXY, Fed, SOFR, U.S. yields              |
| Commodities      | Brent crude, gas, OPEC                   |
| Capital Flows    | FDI, portfolio flows, Gulf financing     |
| Bond Markets     | Eurobond yields, spreads                 |
| Banking Risk     | Liquidity, collateral stress             |
| Geopolitics      | Gulf expansion, sanctions, conflicts     |
| Derivatives      | TRS structures, collateralized financing |

---

# THE HIDDEN REALITY

Most retail investors only see:

* headlines,
* politics,
* social media narratives.

Institutional macro analysts track:

* funding structures,
* collateral,
* liquidity transmission,
* refinancing schedules,
* hidden leverage,
* cross-border capital dependency.

That is where the real signal lives.

---

# WHAT PROFESSIONALS ACTUALLY USE

Top-tier macro desks use:

* Bloomberg Terminal,
* Reuters Eikon,
* TradingEconomics,
* IMF databases,
* BIS data,
* sovereign bond feeds,
* central bank releases.

---

# THE MOST IMPORTANT LESSON

Never track only the event.

Track:

1. the funding structure,
2. the collateral,
3. the currency mismatch,
4. the refinancing timeline,
5. the geopolitical incentives,
6. the liquidity environment,
7. and the second-order consequences.

That is how you move from:
“news consumer”
to
“systemic macro analyst.”

[1]: https://www.imf.org/en/countries/nga?utm_source=chatgpt.com "Nigeria and the IMF"
[2]: https://www.reuters.com/world/africa/imf-says-nigeria-reforms-boost-stability-millions-still-poverty-2026-06-09/?utm_source=chatgpt.com "IMF warns Nigeria of risks in $5 billion swap deal with UAE lender"

# 1. Funding Structure

**Question:** What exactly is the deal structure?

Track:

* IMF reports
* DMO releases
* Reuters/Bloomberg deal descriptions
* Bond prospectuses
* Parliamentary approvals

Look for:

* TRS?
* Eurobond?
* Repo?
* Commodity-backed loan?
* Collateralized financing?
* Variable/fixed rate?
* Dollar or naira denomination?

Core signal:

> “How does the money actually flow?”

---

# 2. Collateral

**Question:** What backs the deal if Nigeria cannot pay?

Track:

* Reuters
* Bloomberg
* Legal filings
* IMF warnings
* Deal term sheets

Look for:

* sovereign bonds,
* oil revenues,
* FX reserves,
* future exports,
* strategic assets.

Critical:

* collateral ratio,
* margin call clauses,
* rehypothecation rights.

Core signal:

> “What can creditors seize or pressure?”

---

# 3. Currency Mismatch

**Question:** Is Nigeria earning in the same currency it owes?

Track:

* USDNGN
* oil exports
* external debt currency composition
* FX reserves

Sources:

* CBN
* TradingView
* IMF
* World Bank

Watch:

* naira depreciation,
* reserve decline,
* rising dollar obligations.

Core signal:

> “Can local cash flows safely service foreign debt?”

---

# 4. Refinancing Timeline

**Question:** When does repayment pressure arrive?

Track:

* debt maturity schedules,
* bond expirations,
* coupon payments,
* rollover windows.

Sources:

* DMO
* IMF DSA reports
* Eurobond prospectuses

Watch:

* debt walls,
* clustered maturities,
* refinancing concentration years.

Core signal:

> “When does liquidity stress hit?”

---

# 5. Geopolitical Incentives

**Question:** Why is the lender really involved?

Track:

* UAE–Africa investment strategy,
* Gulf expansion,
* energy diplomacy,
* trade corridors,
* military/security ties.

Sources:

* Financial Times
* Reuters
* Chatham House
* MEI
* official state visits

Watch:

* ports,
* mining,
* energy assets,
* logistics infrastructure.

Core signal:

> “What strategic influence comes with the money?”

---

# 6. Liquidity Environment

**Question:** Is global money easy or tight?

Track:

* Fed rates,
* DXY,
* US10Y yields,
* SOFR,
* EM bond spreads,
* oil prices.

Sources:

* TradingView
* Federal Reserve
* Bloomberg
* Reuters

Watch:

* rising yields,
* stronger dollar,
* falling oil.

Core signal:

> “Can emerging markets still access cheap dollars?”

---

# 7. Second-Order Consequences

**Question:** What breaks later because of this deal?

Track:

* inflation,
* FX pressure,
* debt servicing ratio,
* reserve depletion,
* social unrest,
* austerity,
* credit downgrades.

Sources:

* IMF
* Fitch
* Moody’s
* Reuters
* local economic data

Watch:

* rising debt service,
* subsidy cuts,
* taxation pressure,
* capital controls,
* banking stress.

Core signal:

> “What systemic fragility does this create later?”

---

# YOUR DAILY MACRO DASHBOARD

Monitor daily:

| Layer          | What To Watch           |
| -------------- | ----------------------- |
| FX             | USDNGN                  |
| Oil            | Brent crude             |
| Dollar Stress  | DXY                     |
| Rates          | US10Y                   |
| Sovereign Risk | Nigeria Eurobond yields |
| Liquidity      | Fed + SOFR              |
| Reserves       | CBN FX reserves         |
| Debt           | DMO maturity schedule   |
| Geopolitics    | UAE–Africa deals        |

---

# SIMPLE PROFESSIONAL WORKFLOW

## Morning

* Reuters
* Bloomberg headlines
* DXY
* Brent
* US10Y
* USDNGN

## Weekly

* IMF
* DMO
* CBN
* bond yields
* reserve data

## Monthly

* debt sustainability
* refinancing map
* reserve trend
* capital flow trend
* geopolitical developments

---

# THE CORE MINDSET SHIFT

Normal news reader:

> “Nigeria got $5B.”

Macro analyst:

> “What collateral, what currency risk, what refinancing profile, what geopolitical leverage, and what systemic fragility transmission does this create?”
