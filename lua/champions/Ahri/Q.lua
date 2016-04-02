Vector2 = require 'Vector2'

function finishCasting()
	local current = Vector2:new(getOwnerX(), getOwnerY())
    local to = (Vector2:new(getSpellToX(), getSpellToY()) - current):normalize()
    local range = to * 880
    local trueCoords = current + range
	addProjectile(trueCoords.x, trueCoords.y)
	end
	
function applyEffects()
	dealMagicalDamage(getEffectValue(0)+getOwner():getStats():getTotalAP()+(0.35*getOwner():getStats():getTotalAp()))
	 addParticleTarget("Ahri_Orb.troybin", getTarget())
	 destroyProjectile()
	 end